#include <iostream>

using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
    }
    ListNode(int val, ListNode* next){
        this->val = val;
        this->next = next;
    }
    ListNode(int* nums, int n){
        ListNode* last = new ListNode(nums[n-1]);
        for (int i = n-2; i > 0; i--){
            ListNode* curr = new ListNode(nums[i], last);
            last = curr;
        }
        this->val = nums[0];
        this->next = last;
    }
    void print(){
        for (ListNode* curr = this; curr != nullptr; curr = curr->next){
            cout << curr->val << "->";
        }
        cout << "NULL" << endl;
    }
};


// a->b->c->d->e->null
// a->reverse(b->c->d->e->null)
// a->(b<-c<-d<-e)
//              ^last
// null<-a<-b<-c<-d<-e return last
ListNode* reverse(ListNode* head){
    if (head->next == nullptr) return head;
    ListNode* last = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
}

// in a range: 1-index, reverse first a ListNode
//
// a->b->c->d->e->null
// h     l  s
//
ListNode* succ = nullptr;
ListNode* reverse(ListNode* head, int a){
    if (a == 1) {
        succ = head->next;
        return head;
    }
    ListNode* last = reverse(head->next, a-1);
    head->next->next = head;
    head->next = succ;
    return last;
}

// in a range: 1-index, reverse a to b ListNode
ListNode* reverse(ListNode* head, int a, int b){
    if (a == 1){
        return reverse(head, a);
    }
    head->next = reverse(head->next, a-1, b-1);
    return head;
}

// use a dummy to reverse ListNode
// 
// dummy->a->b->c->d->e
//           ^     ^
// (1) find the previous node for a-index.
//
ListNode* reverseBetween(ListNode* head, int a, int b){
    ListNode* dummy = new ListNode(-1, head);
    ListNode* prev = dummy;
    ListNode* curr = head;
    ListNode* next = nullptr;

    for (int i = 0; i < a - 1; i++){
        prev = prev->next;
    }
    curr = prev->next;

    // prev ->curr ->next
    // prev<->curr   next


    for (int i = a; i < b; i++){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return dummy->next;
}

//    a->b->c->d->e->null
// p  c  n
//
// n<-a  b->c->d->e->null
//    p  c  n
//
// p = null, c = head, n = head->next
// c->next = p;
// c = n
// p = p->next

ListNode* reverseWholeList(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;

    while (curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return head;
}



int main(){
    int nums[] = {1,2,3,4,5};
    int n = sizeof(nums)/sizeof(int);
    ListNode* head = new ListNode(nums, n);
    head->print();
    ListNode* revHead = reverseWholeList(head);
    revHead->print();

    return 0;
}