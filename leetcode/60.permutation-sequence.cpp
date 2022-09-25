#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        list<int> candidates;
        int prod = 1;
        string res;
        for (int i = 1; i <= n; i++){
            candidates.push_back(i);
            prod *= i;
        }
        k--;
        for (int i = n; i > 0; i--){
            prod /= i;
            int cnt = k/prod;
            auto it = candidates.begin();
            while (cnt-- > 0) it++;
            res += to_string(*it);
            candidates.erase(it);
            k %= prod;
        }
        return res;
    }
};
// @lc code=end

// prod = 6
// k = 8
// 8/6 = 1 .. 2
// 2/2 = 1 .. 0
// 0/1 = 0 .. 0
// 1,[2],3,4
// 1,[3],4
// [1],4
// [4]

