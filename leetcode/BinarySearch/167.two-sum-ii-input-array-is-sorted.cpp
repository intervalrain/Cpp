/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    // binarySearch
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left < right){
            int x = nums[left] + nums[right];
            int mid = left + (right-left)/2;
            if (x == target){
                return {left+1, right+1};
            } else if (x < target){
                if (nums[mid] + nums[right] < target){
                    left = mid + 1;
                } else {
                    left++;
                }
            } else {
                if (nums[mid] + nums[left] > target){
                    right = mid - 1;
                } else {
                    right--;
                }
            }
        }
        return {-1,-1};
    }
    
    // hash table
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     unordered_map<int,int> map;
    //     for (int i = 0; i < nums.size(); i++){
    //         if (map.count(target-nums[i])){
    //             return {map[target-nums[i]]+1, i+1};
    //         }
    //         map[nums[i]] = i;
    //     }
    //     return {-1,-1};
    // }
};
// @lc code=end

