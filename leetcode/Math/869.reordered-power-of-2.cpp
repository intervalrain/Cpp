#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 */

// @lc code=start
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if (n == 1) return true;
        int a = 1;
        string target = encode(n);
        for (int i = 0; i < 31; i++){
            a <<= 1;
            if (encode(a).length() != target.length()) continue;
            if (encode(a) == target) return true;
            if (a/10 > n) break;
        }
        return false;
        
    }
    string encode(int n){
        int cnt[10] = {0};
        string str;
        while (n > 0){
            cnt[n%10]++;
            n/=10;
        }
        for (int i = 9; i >= 0; i--){
            while (cnt[i] > 0){
                cnt[i]--;
                str.push_back(i);
            }
        }
        return str;
    }
};
// @lc code=end

