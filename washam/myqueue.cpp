#include "mylist.cpp"

using namespace std;

template <typename T>
class myqueue{
private:
    mylist<T>* lst;
public:
    myqueue(){
        lst = new mylist<T>();
    }
    myqueue(T* a, T* b){
        lst = new mylist<T>(a, b);
    }
    ~myqueue(){
        lst = NULL;
    }
    int size(){
        return lst->size();
    }
    bool is_empty(){
        return size() == 0;
    }

    // enqueue
    void offer(T item){
        lst->push_back(item);
    }

    // dequeue
    T poll(){   
        return lst->pop_front();
    }

    T peek(){
        return lst->front();
    }

    void clear(){
        while (size() != 0){
            poll();
        }
    }

    void print(){
        lst->print();
    }
};

int main(){
    myqueue<int> q;
    
    cout << "After offering [1,2,3,4]" << endl;
    q.offer(1);
    q.offer(2);
    q.offer(3);
    q.offer(4);
    
    cout << "print result: ";
    q.print();

    cout << "print queue's size: " << q.size() << endl;

    cout << "Construct a queue with array" << endl;
    int arr[] = {0,9,2,1,5,4,3,2,1,0};
    int n = sizeof(arr)/sizeof(int);
    myqueue<int> q2(arr, arr + n);

    cout << "print result: ";
    q2.print();
    cout << "print queue's size: " << q2.size() << endl;
    cout << "print queue is empty or not? " << (q2.is_empty() ? "empty" : "not empty") << endl;
    
    cout << "After executing 4 times of polling" << endl;
    cout << q2.poll() << endl;
    cout << q2.poll() << endl;
    cout << q2.poll() << endl;
    cout << q2.poll() << endl;

    cout << "print result: ";
    q2.print();
    cout << "print queue's size: " << q2.size() << endl;
    cout << "print queue is empty or not? " << (q2.is_empty() ? "empty" : "not empty") << endl;


    cout << "print queue's front: " << q2.peek() << endl;
    cout << "print result: ";
    q2.print();
    cout << "print queue's size: " << q2.size() << endl;
    cout << "print queue is empty or not? " << (q2.is_empty() ? "empty" : "not empty") << endl;

    cout << "Execute clear(): " << endl;
    q2.clear();
    cout << "print queue's size: " << q2.size() << endl;
    cout << "print queue is empty or not? " << (q2.is_empty() ? "empty" : "not empty") << endl;


    return 0;
}

