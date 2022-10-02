#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=2090 lang=cpp
 *
 * [2090] K Radius Subarray Averages
 */

// @lc code=start
#define ll long long
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> res(nums.size(), -1);
        int len = 2*k+1;
        int left = 0, right = 0;
        ll sum = 0;
        while (right < nums.size()){
            sum += nums[right++];
            if (right - left == 2*k+1){
                int mid = (left + right)/2;
                res[mid] = sum/len;
                sum -= nums[left++];
            }
        }
        return res;        
    }
};
// @lc code=end

