#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        if (!head) return;

        // find middle of the list
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        // reverse the half of the list
        ListNode* mid = reverse(slow->next);
        slow->next = NULL;

        // reorder one by one
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        fast = mid;
        slow = head;
        while (fast && slow){
            curr->next = slow;
            slow = slow->next;
            curr = curr->next;
            curr->next = fast;
            fast = fast->next;
            curr = curr->next;
        }
        curr->next = slow;
    }

    ListNode* reverse(ListNode* head){
        if (!head) return NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while (curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
// @lc code=end

