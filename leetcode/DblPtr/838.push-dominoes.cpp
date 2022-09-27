#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

// @lc code=start
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> left(n), right(n);
        string res;
        int force = 0;
        for (int i = 0; i < n; i++){
            if (dominoes[i] == 'R')
                force = n;
            else if (dominoes[i] == 'L')
                force = 0;
            else if (dominoes[i] == '.')
                force = max(force-1, 0);
            
            right[i] = force;
        }       
        for (int i = n-1; i >= 0; i--){
            if (dominoes[i] == 'L')
                force = n;
            else if (dominoes[i] == 'R')
                force = 0;
            else if (dominoes[i] == '.')
                force = max(force-1, 0);

            left[i] = force;
        }
        for (int i = 0; i < n; i++){
            if (left[i] > right[i])
                res.push_back('L');
            else if (right[i] > left[i])
                res.push_back('R');
            else
                res.push_back('.');
        }
        return res;
    }
};
// @lc code=end

