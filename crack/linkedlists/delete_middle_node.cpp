#include <iostream>
#include <assert.h>
#include "listnode.cpp"

/**
 * Implement an algorithm to delete a node in a node in the middle (i.e., any node but the first and last node,
 * not necessarily the exact middle) of a singly linked list,
 * given only access to that node.
 */

using namespace std;

class Solution{
  public:
    bool deleteNode(ListNode* node){
        if (node->next == NULL) return false; // assert node's next not be NULL
        node->val = node->next->val;          // assign the next node's value to self.
        node->next = node->next->next;         // delete the next node
        return true;
    }
};

int main(){
    Solution* sol = new Solution();
    vector<int> nums = {1,2,3,4,5,6};
    ListNode* head = new ListNode(nums);
    sol->deleteNode(head->next->next);  // delete 3

    head->print();
    return 0;
}
