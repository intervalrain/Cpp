#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (int x : nums){
            if (set.count(x)) return true;
            set.insert(x);
        }
        return false;
    }
};
// @lc code=end

