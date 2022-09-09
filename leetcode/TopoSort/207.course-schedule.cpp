#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> map(n);
        vector<int> limit(n);
        for (const auto& pre : p){
            map[pre[1]].push_back(pre[0]);
            limit[pre[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++){
            if (limit[i] == 0) q.push(i);
        }
        while (!q.empty()){
            int x = q.front();
            q.pop();
            n--;
            for (int i : map[x]){
                if (--limit[i] == 0) q.push(i);
            }
        }
        return n == 0;
    }
};
// @lc code=end
