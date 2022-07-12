#include "mylist.cpp"

using namespace std;

template <typename T>
class mystack{
private:
    mylist<T>* lst;
public:
    mystack(){
        lst = new mylist<T>();
    }
    mystack(T* a, T* b){
        lst = new mylist<T>(a, b);
    }
    ~mystack(){
        lst = NULL;
    }
    int size(){
        return lst->size();
    }
    bool is_empty(){
        return size() == 0;
    }

    void push(T item){
        lst->push_back(item);
    }

    T pop(){   
        return lst->pop_back();
    }

    T peek(){
        return lst->back();
    }

    T top(){
        return lst->back();
    }

    void clear(){
        while (size() != 0){
            pop();
        }
    }

    void print(){
        lst->print();
    }
};

int main(){
    mystack<int> st;
    
    cout << "After pushing [1,2,3,4]" << endl;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    
    cout << "print result: ";
    st.print();

    cout << "print stack's size: " << st.size() << endl;

    cout << "Construct a stack with array" << endl;
    int arr[] = {0,9,2,1,5,4,3,2,1,0};
    int n = sizeof(arr)/sizeof(int);
    mystack<int> st2(arr, arr + n);

    cout << "print result: ";
    st2.print();
    cout << "print stack's size: " << st2.size() << endl;
    cout << "print stack is empty or not? " << (st2.is_empty() ? "empty" : "not empty") << endl;
    
    cout << "After executing 4 times of popping" << endl;
    cout << st2.pop() << endl;
    cout << st2.pop() << endl;
    cout << st2.pop() << endl;
    cout << st2.pop() << endl;

    cout << "print result: ";
    st2.print();
    cout << "print stack's size: " << st2.size() << endl;
    cout << "print stack is empty or not? " << (st2.is_empty() ? "empty" : "not empty") << endl;


    cout << "print stack's top: " << st2.peek() << endl;
    cout << "print result: ";
    st2.print();
    cout << "print stack's size: " << st2.size() << endl;
    cout << "print stack is empty or not? " << (st2.is_empty() ? "empty" : "not empty") << endl;

    cout << "Execute clear(): " << endl;
    st2.clear();
    cout << "print stack's size: " << st2.size() << endl;
    cout << "print stack is empty or not? " << (st2.is_empty() ? "empty" : "not empty") << endl;


    return 0;
}

