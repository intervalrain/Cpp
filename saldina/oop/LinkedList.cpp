#include <iostream>
#include <stddef.h>
#include <stdbool.h>

using std::cout;
using std::endl;

class LinkedList;

class Node{
private:
    int val;
    Node *next;
public:
    Node():val(0),next(0){};
    Node(int data):val(data),next(NULL){};
    Node(int data, Node *nextnode):val(data),next(nextnode){};

    friend class LinkedList;
};

class LinkedList{
private:
    Node *head;
    int len;

    Node* getNode(int index){
        Node *curr = head;
        for (int i = 0; i < index; i++){
            curr = curr->next;
        }
        return curr;
    }

public:
    LinkedList():head(0),len(0){}

    void printList(){
        if (head == NULL){
            cout << "List is empty." << endl;
            return;
        }
        Node *curr = head;
        cout << "[";
        while (curr->next != NULL){
            cout << curr->val << ", ";
            curr = curr->next;
        }
        cout << curr->val << "]" << endl;
    }

    void add(int x){
        Node *node = new Node(x);
        if (head == NULL){
            len++;
            head = node;
            return;
        }
        Node *curr = getNode(len-1);
        curr->next = node;
        len++;
    }

    void push_back(int x){
        add(x);
    }
    void push_front(int x){
        Node *node = new Node(x);
        len++;
        node->next = head;
        head = node;
    }
    void trim(int x){
        if (head == NULL){
            cout << "List is empty." << endl;
            return;
        }
        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL && curr->val != x){
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL){
            cout << "There is no " << x << "in the list." << endl;
        } else if (curr == head){
            head = curr->next;
            delete curr;
            curr = NULL;
        } else {
            prev->next = curr->next;
            delete curr;
            curr = NULL;
        }
    }

    void remove(int index){
        if (index < 0 || index > len - 1)
            return;
        if (index == 0){
            Node *next = head->next;
            delete head;
            head = next;
            len--;
            return;
        }
        Node *node = getNode(index-1);
        Node *next = node->next->next;
        delete node->next;
        node->next = next;
        len--;
    }
    void clear(){
        if (head == NULL)
            return;
        Node *curr = head;
        Node *next = head->next;
        while (curr->next != NULL){
            delete curr;
            curr = next;
            next = curr->next;
        }
        delete curr;
        curr = NULL;
        head = NULL;
        next = NULL;
        len = 0;
    }
    void reverse(){
        if (head == NULL || head->next == NULL)
            return;
        Node *prevnode = NULL;
        Node *currnode = head;
        Node *nextnode = head->next;
        while (nextnode != NULL){
            currnode->next = prevnode;
            prevnode = currnode;
            currnode = nextnode;
            nextnode = currnode->next;
        }
        currnode->next = prevnode;
        head = currnode;
    }
    int size(){
        return len;
    }


};



int main() {

    LinkedList list;     // 建立LinkedList的object
    list.printList();    // 目前list是空的
    list.trim(4);      // list是空的, 沒有4
    list.push_back(5);   // list: 5
    list.push_back(3);   // list: 5 3
    list.push_front(9);  // list: 9 5 3
    list.printList();    // 印出:  9 5 3
    list.push_back(4);   // list: 9 5 3 4
    list.trim(9);      // list: 5 3 4
    list.printList();    // 印出:  5 3 4
    list.push_front(8);  // list: 8 5 3 4
    list.printList();    // 印出:  8 5 3 4
    list.reverse();      // list: 4 3 5 8
    list.printList();    // 印出:  4 3 5 8
    list.clear();        // 清空list
    list.printList();    // 印出: List is empty.

    return 0;
}