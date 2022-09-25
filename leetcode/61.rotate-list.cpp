#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode* curr = head;
        int n = 0; 
        while (curr){
            curr = curr->next;
            n++;
        }
        k %= n;
        if (k == 0) return head;
        ListNode* fast, *slow;
        fast = head, slow = head;
        while (k-- && fast) fast = fast->next;
        while (fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        ListNode* res = slow->next;
        slow->next = NULL;
        return res;
    }
};
// @lc code=end

