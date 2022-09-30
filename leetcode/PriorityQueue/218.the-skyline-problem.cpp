#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int> memo;
    priority_queue<int> remove(priority_queue<int>& pq, int target){
        if (pq.top() == target){
            pq.pop();
            while (memo.count(pq.top()) && memo[pq.top()] > 0){
                memo[pq.top()]--;
                pq.pop();
            }
        } else {
            memo[target]++;
        }
        return pq;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<vector<int>> height;
        for (const auto& b : buildings){
            height.push_back({b[0], -b[2]});
            height.push_back({b[1], b[2]});
        }
        sort(height.begin(), height.end());
        priority_queue<int> pq;
        pq.push(0);
        int prev = 0;
        for (const auto& h : height){
            if (h[1] < 0){
                pq.push(-h[1]);
            } else {
                pq = remove(pq, h[1]);
            }
            int curr = pq.top();
            if (prev != curr){
                res.push_back({h[0], curr});
                prev = curr;
            }
        }
        return res;
    }
};
// @lc code=end

