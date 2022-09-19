#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> set;
        for (int x : nums1){
            set.insert(x);
        }
        for (int y : nums2){
            if (set.count(y)){
                res.insert(y);
            }
            if (res.size() == set.size()) break;
        }
        return vector<int>(res.begin(), res.end());
    }
};
// @lc code=end

