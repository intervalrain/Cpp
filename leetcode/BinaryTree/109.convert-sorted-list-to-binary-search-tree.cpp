/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* curr = head;
        vector<int> nums;
        while (curr){
            nums.push_back(curr->val);
            curr = curr->next;
        }
        return build(nums, 0, nums.size()-1);
    }
    TreeNode* build(vector<int>& nums, int left, int right){
        if (left > right) return NULL;
        int mid = left + (right-left)/2;
        return new TreeNode(nums[mid], build(nums, left, mid-1), build(nums, mid+1, right));
    }
};
// @lc code=end

