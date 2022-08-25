#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* curr = dummy;
        while (curr){
            while (curr->next && curr->next->val == val){
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};
// @lc code=end

