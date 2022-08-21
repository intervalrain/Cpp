/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next){
            return head;
        }
        ListNode* nextnext = swapPairs(head->next->next);
        ListNode* last = head->next;
        head->next->next = head;
        head->next = nextnext;
        return last;

    }
};
// @lc code=end

// 1->2->4->3
// 2->1->4->3