#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> set = {'a','e','i','o','u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0, right = s.length()-1;
        while (left < right){
            while (left < right && !set.count(s[left])) left++;
            while (left < right && !set.count(s[right])) right--;
            swap(s[left++], s[right--]);
        }
        return s;
    }
};
// @lc code=end

