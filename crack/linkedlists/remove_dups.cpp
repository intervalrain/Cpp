#include <iostream>
#include <unordered_set>
#include "listnode.cpp"

/**
 * Write a code to remove duplicates from an unsorted linked list.
 */

using namespace std;

class Solution{
  public:
    // time: O(n)
    void deleteDups(ListNode* head){
        unordered_set<int> set;
        ListNode* curr = head;
        while (curr != NULL){
            if (!set.count(curr->val)){
                set.insert(curr->val);
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
    }

    // time: O(n^2), space O(1)
    void removeDups(ListNode* head){
        ListNode* curr = head;
        while (curr != NULL){
            ListNode* runner = curr;
            while (runner->next != NULL){
                if (runner->next->val == curr->val){
                    runner->next = runner->next->next;
                } else {
                    runner = runner->next;
                }
            }
            curr = curr->next;
        }
    }
};

int main(){
    Solution* sol = new Solution();
    vector<int> nums = {1,1,2,2,3,3,4,4,5,5};
    ListNode* h1 = new ListNode(nums);
    sol->deleteDups(h1);
    h1->print();

    ListNode* h2 = new ListNode(nums);
    sol->removeDups(h2);
    h2->print();

    return 0;
}
