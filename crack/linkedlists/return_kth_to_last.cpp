#include <iostream>
#include <vector>
#include "listnode.cpp"

using namespace std;

class Solution{
  public:
    int printKthToLast(ListNode* head, int k){
        if (!head){
            return 0;
        }
        int index = printKthToLast(head->next, k) + 1;
        if (index == k){
            cout << k << "th to last node is " << head->val;
        }
        return index;
    }
    ListNode* nthToLast(ListNode* head, int k, int& i){
        if (!head) return NULL;
        ListNode* node = nthToLast(head->next, k, i);
        i++;
        if (i == k){
            return head;
        }
        return node;
    }
    ListNode* nthToLast(ListNode* head, int k){
        int i = 0;
        return nthToLast(head, k, i);
    }

    ListNode* iterNthToLast(ListNode* head, int k){
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (k--){
            p1 = p1->next;
        }
        while (p1){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }

};

int main(){
    Solution* sol = new Solution();
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    ListNode* head = new ListNode(nums);

    sol->printKthToLast(head, 3); //7
    cout << endl;

    int k = 3;
    ListNode* res = sol->nthToLast(head, k);
    cout << k << "th to last node is " << res->val << endl;

    ListNode* ans = sol->iterNthToLast(head, k);
    cout << k << "th to last node is " << ans->val << endl;

    return 0;
}
