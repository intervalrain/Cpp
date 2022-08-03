#include <iostream>
#include <vector>
#include "listnode.cpp"

/**
 * Write code to partition a linked list around a value x,
 * such that all nodes less than x come before all nodes greater than or equal to x.
 * (IMPORTANT: The partition element x can appear anywhere in the "right partiton";
 * it does not need to appear between the left and right partitons.)
 */

using namespace std;

class Solution{
  public:
    ListNode* partition(ListNode* head, int x){
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        ListNode* p1 = dummy1;
        ListNode* p2 = dummy2;
        ListNode* curr = head;
        while (curr){
            if (curr->val < x){
                p1->next = curr;
                p1 = p1->next;
            } else {
                p2->next = curr;
                p2 = p2->next;
            }
            curr = curr->next;
        }
        p1->next = dummy2->next;
        p2->next = nullptr;
        return dummy1->next;
    }
};

int main(){
    Solution* sol = new Solution();
    vector<int> nums = {3,5,8,5,10,2,1};
    int x = 5;
    ListNode* node = new ListNode(nums);
    node->print();
    ListNode* res = sol->partition(node, x);  // 3->1->2--->10->5->5->8
    res->print();

    return 0;
}
