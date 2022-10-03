#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=817 lang=cpp
 *
 * [817] Linked List Components
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
    int numComponents(ListNode* head, vector<int>& nums) {
        ListNode* curr = head;
        unordered_set<int> set(nums.begin(), nums.end());
        bool mode = false;
        int cnt = 0;
        while (curr){
            if (set.find(curr->val) != set.end()){
                if (!mode) cnt++;
                mode = true;
            } else {
                mode = false;
            }
            curr = curr->next;
        }
        return cnt;
    }
};
// @lc code=end

