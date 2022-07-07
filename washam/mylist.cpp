#include <iostream>
#include <cstdlib>
#include "util.cpp"

using namespace std;

template <typename T>
class node{
public:
    node* next;
    node* prev;
    T val;

    node(){}
    node(T item){
        val = item;
    }
    node(T item, node* next){
        val = item;
        this->next = next;
    }
    node(T item, node* next, node* prev){
        val = item;
        this->next = next;
        this->prev = prev;
    }
    ~node(){
        if (next != NULL){
            next = NULL;
        }
    }
    bool hasNext(){
        return next != NULL;
    }
    bool hasPrev(){
        return prev != NULL;
    }
};


template <typename T>
class mylist{
private:
    node<T>* dummy;
    int length;
public:
    mylist(){
        dummy = new node<T>();
        length = 0;
    }
    mylist(T* a, T* b){
        if (b < a)
            throw OutOfRange();
        dummy = new node<T>();
        for (auto it = b - 1; it != a - 1; it--){
            push_front(*it);
        }
        length = b - a;
    }
    ~mylist(){
        node<T>* curr = dummy;
        node<T>* next = curr->next;
        if (next != NULL){
            curr = next;
            next = next->next;
            curr = NULL;
        }
        curr = NULL;
    }
    int size(){
        return length;
    }
    bool is_empty(){
        return size() == 0;
    }

    void checkBound(int index){
        if (index < 0 || index >= size()){
            throw OutOfRange(size(), index);
        }
    }

    node<T>* getNode(int index){
        checkBound(index);
        node<T>* curr;
        if (index < size()/2){
            curr = dummy->next;
            while (index-- > 0){
                curr = curr->next;
            }
        } else {
            index = size() - index;
            curr = dummy;
            while (index-- > 0){
                curr = curr->prev;
            }
        }
        return curr;
    }

    T at(int index){
        if (index < 0) index += size();
        checkBound(index);
        return getNode(index)->val;
    }

    T operator[](int index){
        return at(index);
    }

    void linkNode(node<T>* first, node<T>* second){
        first->next = second;
        second->prev = first;
    }

    void push_front(T item){
        node<T>* newnode = new node<T>(item);
        node<T>* nextnode = dummy->hasNext() ? dummy->next : dummy;
        linkNode(dummy, newnode);
        linkNode(newnode, nextnode);
        length++;
    }
    void push_back(T item){
        node<T>* newnode = new node<T>(item);
        node<T>* prevnode = dummy->hasPrev() ? dummy->prev : dummy;
        linkNode(prevnode, newnode);
        linkNode(newnode, dummy);
        length++;
    }
    T pop_front(){
        if (length == 0) throw OutOfRange();
        int tmp = dummy->next->val;
        node<T>* nextnode = dummy->next->next;
        dummy->next = NULL;
        linkNode(dummy, nextnode);
        length--;
        return tmp;
    }
    T pop_back(){
        if (length == 0) throw OutOfRange();
        int tmp = dummy->prev->val;
        node<T>* prevnode = dummy->prev->prev;
        dummy->prev = NULL;
        linkNode(prevnode, dummy);
        length--;
        return tmp;

    }
    T front(){
        if (size() == 0) throw OutOfRange();
        return dummy->next->val;
    }
    T back(){
        if (size() == 0) throw OutOfRange();
        return dummy->prev->val;
    }
    void insert(int index, T item){
        if (index == 0){
            push_front(item);
        } else if (index == size()){
            push_back(item);
        } else {
            node<T>* prev = getNode(index-1);
            node<T>* newnode = new node<T>(item);
            linkNode(newnode, prev->next);
            linkNode(prev, newnode);
        }
        length++;
    }

    void erase(int index){
        if (index < 0) index += size();
        checkBound(index);
        
        if (index == 0){
            pop_front();
        } else if (index == size() - 1){
            pop_back();
        } else {
            node<T>* prev = getNode(index-1);
            linkNode(prev, prev->next->next);
        }
        length--;
    }
    void reverse(){
        if (size() == 0 || size() == 1) return;
        node<T>* prev = dummy;
        node<T>* curr = dummy->next;
        node<T>* next = curr->next;

        for (int i = 0; i < size(); i++){
            linkNode(curr, prev);
            prev = curr;
            curr = next;
            next = next->next;
        } 

    }
    void remove(int item){
        node<T>* curr = dummy->next;
        while (curr != dummy){
            if (curr->val == item){
                linkNode(curr->prev, curr->next);
                break;
            } else {
                curr = curr->next;
            }   
        }
        length--;
    }
    void removeAll(int item){
        node<T>* curr = dummy->next;
        while (curr != dummy){
            if (curr->val == item){
                node<T>* tmp = curr->next;
                linkNode(curr->prev, curr->next);
                curr = tmp;
                length--;
            } else {
                curr = curr->next;
            }
        }
    }
    void print(){
        node<T>* curr = dummy->next;
        cout << "[";
        for (int i = 1; i < size(); i++){
            cout << curr->val << ", ";
            curr = curr->next;
        }
        cout << curr->val << "]" << endl;
    }
};

int main(){
    mylist<int> list;
    mylist<int> list2;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_back(5);
    cout << list.at(2) << endl;
    cout << list.at(-1) << endl;

    
    list.print();
    cout << list.size() << endl;

    cout << list.is_empty() << endl;
    cout << list2.is_empty() << endl;

    cout << list[1] << endl;

    list.insert(3,-1);
    list.print();

    list.erase(1);
    list.print();

    int nums[] = {1,2,3,4,4,4,4,4,4,5,6,7};
    int n = sizeof(nums)/sizeof(int);
    mylist<int> list3(nums, nums+n);
    list3.print();

    list3.removeAll(4);
    list3.print();
    list3.remove(3);
    list3.print();

    return 0;
}

