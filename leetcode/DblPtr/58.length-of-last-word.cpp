#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int right = n-1;
        while (right >= 0 && s[right] == ' ') right--;
        int left = right;
        while (left >= 0 && s[left] != ' ') left--;

        return right-left;
    }
};
// @lc code=end

