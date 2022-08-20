/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 */

// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if (nums.size() < 3) return false;
        unordered_map<int,int> freq;
        unordered_map<int,vector<vector<int>>> need;
        for (int x : nums) freq[x]++;
        for (int x : nums){
            if (freq[x] == 0) continue;
            if (need.count(x) && need[x].size() > 0){
                freq[x]--;
                vector<int> seq = need[x].back();
                need[x].pop_back();
                seq.push_back(x);
                need[x+1].push_back(seq);
            } else if (freq[x] > 0 && freq[x+1] > 0 && freq[x+2] > 0){
                freq[x]--;
                freq[x+1]--;
                freq[x+2]--;
                vector<int> seq{x, x+1, x+2};
                need[x+3].push_back(seq);
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
// need[5] = {1,2,3,4}
// need[6] = {3,4,5},{3,4,5}
//
//
// 1 2 3 3 3 4 4 4 5 5 
// 1: 0
// 2: 0
// 3: 0
// 4: 0
// 5: 0
