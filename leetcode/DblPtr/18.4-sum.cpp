#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int s = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0; i<s-3; i++) {
            if(i==0 || nums[i]!=nums[i-1]) {
                for(int j=i+1; j<s-2; j++) {
                    if(j==i+1 || nums[j]!=nums[j-1]) {
                        int k=j+1, l = s-1;
                        while(k < l) {
                            long long int sum1 = nums[i] + nums[j];
                            long long int sum2 = nums[k] + nums[l];
                            if(sum1 == target-sum2) {
                                res.push_back({nums[i],nums[j],nums[k],nums[l]});
                                k++,l--;
                                while(k<=l && nums[k]==nums[k-1])
                                    k++;
                                while(l>=k && nums[l]==nums[l+1])
                                    l--;
                            }
                            else if(sum1 > target-sum2)
                                l--;
                            else
                                k++;
                        }
                    }
                }
            }
        }        
        return res;
    }
};
// @lc code=end

