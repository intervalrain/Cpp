#include <iostream>
#include "listnode.cpp"

using namespace std;

class Solution{
public:
    ListNode* sortList(ListNode* head){
        if (head == NULL || head->next == NULL){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return merge(l1, l2);
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while (l1 != NULL && l2 != NULL){
            if (l1->val < l2->val){
                curr->next = l1;
                l1 = l1->next;
            } else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1 == NULL){
            curr->next = l2;
        }
        if (l2 == NULL){
            curr->next = l1;
        }
        return dummy->next;
    }
};

int main(){
    Solution* sol = new Solution();
    vector<int> nums = {-1,3,7,5,2,9,0};
    ListNode* head = new ListNode(nums);
    ListNode* node = sol->sortList(head);

    node->print();

    return 0;
}
