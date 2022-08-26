#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for (int i = s.length()-1; i >= 0; i--){
            switch(s[i]){
                case 'M': 
                    res += 1000; 
                    break;
                case 'D': 
                    res += 500;  
                    break;
                case 'C': 
                    res += (res > 400 ? -100 : 100);  
                    break;
                case 'L': 
                    res += 50;   
                    break;
                case 'X': 
                    res += (res > 40 ? -10 : 10);   
                    break;
                case 'V': 
                    res += 5;
                    break;
                case 'I': 
                    res += (res > 4 ? -1 : 1);    
                    break;
                default: 
                    break;
            }
        }
        return res;
    }
};
// @lc code=end

// MCMXCIV
// 5 - 1 + 100 - 10 + 1000 - 100 + 1000 