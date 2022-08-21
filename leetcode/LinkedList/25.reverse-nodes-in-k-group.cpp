/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     ListNode* curr = head;
    //     int cnt = 0;
    //     while (curr && cnt != k){
    //         curr = curr->next;
    //         cnt++;
    //     }
    //     if (cnt == k){
    //         curr = reverseKGroup(curr, k);
    //         while (cnt-- > 0){
    //             ListNode* next = head->next;
    //             head->next = curr;
    //             curr = head;
    //             head = next;
    //         }
    //         head = curr;
    //     }
    //     return head;
    //  }
    int size(ListNode* head){
        if(head == NULL){
            return 0;
        }
        return 1 + size(head->next);
    }
    ListNode* reverse(ListNode* head , int k , int size){
        if(head == NULL) return head;
        if(size < k) return head;
        
        int n = 0;
        ListNode* slow = NULL;
        ListNode* curr = head;
        ListNode* fast = head;
        
        while(fast != NULL && n < k){
            fast = fast->next;
            curr->next = slow;
            slow = curr;
            curr = fast;
            n++;
        }
        
        head->next = reverse(fast , k , size - k);
        
        return slow; 
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int a = size(head);
        ListNode* ans = reverse(head , k , a);
        return ans;
    }        
};
// @lc code=end

//       1->2->3->6->5->4->7
//       h  n     cur
//       3->2->1->6->5->4->7
//    h  c
//    n