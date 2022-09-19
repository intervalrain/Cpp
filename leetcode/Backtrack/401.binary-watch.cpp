#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start
class Solution {
public:
    vector<int> tab = {-1,-2,-4,-8,-16,-32,1,2,4,8};
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        backtrack(turnedOn, res, 0, 0, 0);
        return res;
    }
    void backtrack(int turn, vector<string>& res, int hr, int min, int ix){
        if (turn == 0){
            if (hr >= 12 || min >= 60) return;
            res.push_back(trans(hr, min));
            return;
        }
        for (int i = ix; i < tab.size(); i++){
            bool flag = tab[i] < 0;
            flag ? (min -= tab[i]) : (hr += tab[i]);
            backtrack(turn-1, res, hr, min, i+1);
            flag ? (min += tab[i]) : (hr -= tab[i]);
        }
    }
    string trans(int hr, int min){
        string smin = to_string(min);
        if (smin.length() == 1) smin = "0" + smin;
        return to_string(hr) + ":" + smin;
    }
};
// @lc code=end

