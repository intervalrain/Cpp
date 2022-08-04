#include <iostream>
#include <vector>
#include "listnode.cpp"

using namespace std;

class Solution{
  public:
    ListNode* cycleBeginAt(ListNode* node){
        ListNode* fast = node;
        ListNode* slow = node;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow){
                break;
            }
        }
        if (!fast) return NULL;
        fast = node;
        while (fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main(){
    Solution* sol = new Solution();
    vector<int> nums = {1,2,3,4,5};
    ListNode* node = new ListNode(nums);
    node->next->next->next->next->next = node->next->next; // 3
    ListNode* result = sol->cycleBeginAt(node);

    cout << result->val << endl;

    return 0;
}
