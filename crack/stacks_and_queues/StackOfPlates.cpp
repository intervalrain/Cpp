#include <iostream>
#include <vector>
#include <stack>

/**
 * Imagine a (literal) stack of plates. If the stack gets too high,
 * it might topple.
 * Therefore, we would likely start a new stack when the previous stack exceeds some threshold.
 * Implement a data structure SetOfStacks that mimics this.
 * SetOfStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity.
 * SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack .
 * that is, pop() should return the same values as it would if there were just a single stack.
 */

using namespace std;

class StackException : public exception{
public:
    string msg;
    StackException(const string& message){
        this->msg = message;
        cout << "StackException::StackException - set msg to: " << this->msg << endl;
    }
    ~StackException(){
        cout << "StackException::StackException" << endl;
    }
    virtual const char* what() const throw(){
          cout << "StackException::what" << endl;
          return msg.c_str();
    }
};

class stackplate{
  private:
    int size;
    int capacity;
    vector<stack<int>*> stacks;

    void newstack(){
        stack<int> *st = new stack<int>;
        stacks.push_back(st);
    }
    void popstack(){
        stacks.pop_back();
    }

    stack<int>* topstack(){
        return stacks[stacks.size()-1];
    }

    void leftShift(int idx){
        if (((stacks.size()-1) * capacity) == size) popstack();
        int k = idx/capacity;
        int f = size/capacity;
        for (int i = k+1; i < f; i++){
            stack<int>* prev = stacks[i-1];
            stack<int>* curr = stacks[i];
            stack<int>* tmpst = new stack<int>();
            int tmp;
            while (!curr->empty()){
                tmp = curr->top();
                tmpst->push(tmp);
                curr->pop();
            }
            tmpst->pop();
            while (!tmpst->empty()){
                curr->push(tmpst->top());
                tmpst->pop();
            }
            prev->push(tmp);
        }
    }

  public:
    stackplate(int cap){
        this->capacity = cap;
        this->size = 0;
    }
    bool isEmpty(){
        return size == 0;
    }
    void push(int val){
        if (stacks.size() * capacity == size) newstack();
        stacks[stacks.size()-1]->push(val);
        size++;
    }
    int pop(){
        if (isEmpty()) throw (StackException("Empty stack exception."));
        if ((stacks.size()-1) * capacity == size) popstack();
        int res = topstack()->top();
        topstack()->pop();
        size--;
        return res;
    }
    int at(int index){
        if (index < 0 || index >= size) throw (StackException("index out of bound exception."));
        stack<int>* tmp = new stack<int>();
        stack<int>* st = stacks[index/capacity];
        while (!st->empty()){
            tmp->push(st->top());
            st->pop();
        }
        int k = index % capacity;
        int res;
        int i = 0;
        while (!tmp->empty()){
            if (i == k) res = tmp->top();
            st->push(tmp->top());
            tmp->pop();
            i++;
        }
        return res;

    }
    int peek(){
        if ((stacks.size()-1) * capacity == size) popstack();
        return topstack()->top();
    }
    int popAt(int index){
        if (index < 0 || index >= size) throw (StackException("index out of bound exception."));
        stack<int>* tmp = new stack<int>();
        int k = index % capacity;
        stack<int>* st = stacks[index/capacity];
        while (!st->empty()){
            tmp->push(st->top());
            st->pop();
        }
        int i = 0;
        int res = 0;
        while (!tmp->empty()){
            if (i == k){
                res = tmp->top();
            } else {
                st->push(tmp->top());
            }
            tmp->pop();
            i++;
        }

        leftShift(index);
        size--;
        return res;
    }
    int length(){
        return size;
    }
};

int main(){
    stackplate st(5);

    st.push(5);
    cout << st.pop() << endl;

    for (int i = 0; i < 5; i++){
        st.push(5*i);
    }
    cout << st.popAt(2) << endl;

    while (st.length() > 0){
        cout << st.pop() << " ";
    }

    return 0;
}

