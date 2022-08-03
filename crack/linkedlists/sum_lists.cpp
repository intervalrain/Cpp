#include <iostream>
#include <vector>
#include "listnode.cpp"

/**
 * You have two numbers represented by a linked list,
 * where each node contains a single digit.
 * The digits are stored in reverse order,
 * such that the 1's digit is at the head of the list.
 * Write a function that adds the two numbers and returns the sum as a linked list.
 * (You are not allowed to "cheat" and just convert the linked list to an integer)
 */

using namespace std;

class Solution{
  public:
    ListNode* add(ListNode* p1, ListNode* p2){
        return helper(p1, p2, 0);
    }
    ListNode* helper(ListNode* p1, ListNode* p2, int cin){
        int sum = p1->val + p2->val + cin;
        cin = sum / 10;
        sum = sum % 10;
        p1->val = sum;
        if (p1->next && p2->next){
            p1->next = helper(p1->next, p2->next, cin);
        } else if (p1->next){
            p1->next = helper(p1->next, new ListNode(0), cin);
        } else if (p2->next){
            p1->next = helper(p2->next, new ListNode(0), cin);
        } else if (!p1->next && !p2->next && cin != 0){
            p1->next = new ListNode(1);
        }
        return p1;
    }
};

int main(){
    Solution* sol = new Solution();
    vector<int> nums1 = {7,1,6};
    vector<int> nums2 = {5,9,2};
    ListNode* p1 = new ListNode(nums1);
    ListNode* p2 = new ListNode(nums2);
    p1->print();
    p2->print();

    ListNode* p3 = sol->add(p1, p2);
    p3->print();

    return 0;
}
