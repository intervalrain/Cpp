/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int i = 0, j = 1;
        while (j < nums.size()){
            if (nums[i] == nums[j]){
                j++;
            } else {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};
// @lc code=end

// 0,1,2,3,4,2,2,3,3,4
//                   ^
//         ^ 