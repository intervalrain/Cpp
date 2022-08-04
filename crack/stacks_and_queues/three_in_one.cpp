#include <iostream>
#include <string>

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

class FixedMultiStack{

// _____ | _____ | _____
// 01234   56789   01234
//

private:
    int no = 3;
    int capacity;
    int* values;
    int* sizes;
    int top(int index){
        int offset = no * capacity;
        int sz = sizes[index];
        return offset + sz - 1;
    }
public:
    ~FixedMultiStack(){
        free(values);
        free(sizes);
    }
    FixedMultiStack(int cap){
        this->capacity = cap;
        this->values = new int[cap * no];
        this->sizes = new int[no];
        //this->values = (int*)malloc(sizeof(int)*cap*no);
        //this->sizes = (int*)malloc(sizeof(int)*no);

    }
    void push(int index, int val){
        if (isFull(index)){
            throw (StackException("Stack is full."));
        }
        sizes[index]++;
        values[top(index)] = val;
    }
    int pop(int index){
        if (isEmpty(index)){
            throw (StackException("Stack is empty."));
        }
        int top_i = top(index);
        int res = values[top_i];
        values[top_i] = 0;
        sizes[index]--;
        return res;
    }
    int peek(int index){
        if (isEmpty(index)){
            throw (StackException("Stack is empty."));
        }
        return values[top(index)];
    }
    bool isEmpty(int index){
        return sizes[index] == 0;
    }
    bool isFull(int index){
        return sizes[index] == capacity;
    }
};

int main(){
    FixedMultiStack* st = new FixedMultiStack(5);
    st->push(0, 3);
    cout << st->pop(0) << endl;
    st->push(1, 2);
    st->push(1, 3);
    cout << st->pop(1) << endl;
    cout << st->pop(1) << endl;

    return 0;

}
