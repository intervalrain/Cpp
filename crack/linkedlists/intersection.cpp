#include <iostream>
#include <vector>
#include "listnode.cpp"

/**
 * Given two (singly) linked lists, determine if the two lists intersect.
 * Return the interscting node.
 * Note that the intersection is defined based on reference, not value.
 * That is, if the kth node of the first linkedlist is the exact node (by reference) as the jth node of the second linkedlists,
 * then they are intersecting.
 */

using namespace std;

class Solution{
  public:
    ListNode* intersection(ListNode* l1, ListNode* l2){
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        bool repeat1 = false;
        bool repeat2 = false;
        while (p1 && p2){
            if (p1 == p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
            if (!p1 && !repeat1){
                p1 = l2;
                repeat1 = true;
            }
            if (!p2 && !repeat2){
                p2 = l1;
                repeat2 = true;
            }
        }
        return nullptr;

    }
};

int main(){
    Solution* sol = new Solution();
    vector<int> v1 = {4,6,7,2,1};
    vector<int> v2 = {3,1,5,9};
    ListNode* l1 = new ListNode(v1);
    ListNode* l2 = new ListNode(v2);
    l2->next->next->next->next = l1->next->next; // intersect at 7
    ListNode* res = sol->intersection(l1, l2);
    cout << res->val << endl;

    return 0;
}

