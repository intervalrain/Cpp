#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

// stack{
//
//   _____ | _____ | _____
//
//   st[0] = {};
//   st[1] = {};
//   st[2] = {};
// }
//
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

class MultiStack{
private:
    int no;
    vector<deque<int>> stack;

public:
    MultiStack(int no){
        this->no = no;
        this->stack = vector<deque<int>>(no, deque<int>());
    }
    void push(int index, int val){
        if (index < 0 || index >= no){
            throw (StackException("Index out of bound."));
        }
        stack[index].push_back(val);
    }
    int pop(int index){
        if (stack[index].size() == 0){
            throw (StackException("Stack is empty"));
        }
        int res = stack[index].back();
        stack[index].pop_back();
        return res;
    }
    int peek(int index){
        if (stack[index].size() == 0){
            throw (StackException("Stack is empty"));
        }
        return stack[index].back();
    }
    bool isEmpty(int index){
        return stack[index].size() == 0;
    }
};

int main(){
    MultiStack* st = new MultiStack(3);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            st->push(i, (i+1)*(j+1));
        }
        for (int j = 0; j < 5; j++){
            cout << st->pop(i) << " ";
        }
        cout << endl;
    }

    return 0;
}


