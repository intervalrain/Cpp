#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b){return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        for (ListNode* node : lists){
            if (node) pq.push(node);
        }
        while (!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();
            curr->next = node;
            curr = curr->next;
            node = node->next;
            if (node) pq.push(node);
        }
        return dummy->next;
    }
};
// @lc code=end

