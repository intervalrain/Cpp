/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    // with inner function
    // vector<int> searchRange(vector<int>& nums, int target) {
    //     if (nums.size() == 0) return {-1,-1};
    //     if (!binary_search(nums.begin(), nums.end(), target)) return {-1,-1};
    //     int left = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
    //     int right = distance(nums.begin(), upper_bound(nums.begin(), nums.end(), target))-1;
    //     return {left, right};
    // }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1,-1};

        int left = search(nums, 0, nums.size()-1, target, -1);
        int right = search(nums, left, nums.size()-1, target, 1);
        return (left >= nums.size() || nums[left] != target) ? (vector<int>{-1,-1}) : (vector<int>{left, right});
    }

    int search(vector<int>& nums, int left, int right, int target, int mode){
        while (left <= right){
            int mid = left + (right-left)/2;
            if (nums[mid] == target){
                if (mode == 0) return mid;
                else if (mode == 1) left = mid +1;
                else if (mode == -1) right = mid - 1;
            } else if (nums[mid] < target){
                left = mid + 1;
            } else if (nums[mid] > target){
                right = mid - 1;
            }
        }
        if (mode == 0) return -1;
        else if (mode == 1) return right;
        return left;
    }
};
// @lc code=end

