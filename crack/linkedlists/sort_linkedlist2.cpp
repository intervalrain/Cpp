#include <iostream>
#include <vector>
#include "listnode.cpp"

using namespace std;

class Solution{
  public:
    ListNode* sortList(ListNode* head){
        if (!head || !(head->next)) return head;

        // get the linked list's length
        ListNode* curr = head;
        int length = 0;
        while (curr){
            curr = curr->next;
            length++;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* left, *right, *tail;
        for (int step = 1; step < length; step <<= 1){
            curr = dummy->next;
            tail = dummy;
            while (curr){
                left = curr;
                right = split(left, step);
                curr = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        return dummy->next;
    }

  private:
    /**
     * Divide the linked list into two lists,
     * while the first list contains first n nodes
     * return the second list's head
     */
    ListNode* split(ListNode* head, int n){
        for (int i = 1; head && i < n; i++){
            head = head->next;
        }
        if (!head) return NULL;
        ListNode* second = head->next;
        head->next = NULL;
        return second;
    }

    /**
     * Merge the two sorted linked list l1 and l2,
     * then append the merged sorted linked list to the node head
     * return the tail of the merged sorted linked list
     */
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head){
        ListNode* curr = head;
        while (l1 && l2){
            if (l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = (l1 ? l1 : l2);

        // to return tail as the last round's prev head.
        while (curr->next) curr = curr->next;
        return curr;
    }
};

int main(){
    Solution* sol = new Solution();
    vector<int> nums = {-1,3,5,2,0,7,9,4};
    ListNode* head = new ListNode(nums);
    ListNode* res = sol->sortList(head);

    res->print();

    return 0;
}
