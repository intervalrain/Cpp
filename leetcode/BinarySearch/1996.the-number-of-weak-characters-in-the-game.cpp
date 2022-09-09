#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=1996 lang=cpp
 *
 * [1996] The Number of Weak Characters in the Game
 */

// @lc code=start
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        map<int,int> memo;
        int cnt = 0;
        for (const auto& p : properties){
            memo[p[0]] = max(memo[p[0]], p[1]);
        }
        
        int curr = 0;
        for (auto it = memo.rbegin(); it != memo.rend(); ++it){
            curr = max(curr, it->second);
            it->second = curr;
        }
        
        for (const auto& p : properties){
            auto it = memo.lower_bound(p[0]);
            it++;
            if (it == memo.end()) continue;
            if (it->second > p[1]) cnt++;
        }
        
        return cnt;
    }
};
// @lc code=end

