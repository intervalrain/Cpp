#include <iostream>
#include <vector>
#include "listnode.cpp"

/**
 * Implement a function to check if a linked list is a palindrome.
 */

using namespace std;

class Solution{
  public:
    bool isPalindrome(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast){
            fast = fast->next;
            slow = slow->next;
        }
        fast = reverse(slow);
        slow = head;
        while (fast){
            if (fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next;
        while (curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
};

int main(){
    Solution* sol = new Solution();
    while (true){
        int n;
        cout << "n = ";
        cin >> n;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) cin >> nums[i];
        ListNode* node = new ListNode(nums);
        if (sol->isPalindrome(node)){
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }

    return 0;
}
