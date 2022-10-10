/*
 * @lc app=leetcode id=1328 lang=cpp
 *
 * [1328] Break a Palindrome
 */

// @lc code=start
class Solution {
public:
    string breakPalindrome(string s) {
        if (s.length() == 1) return "";
        for (int i = 0; i < s.length(); i++){
            if (s[i] != 'a'){
                if (s.length() % 2 == 1 && s.length()/2 == i) continue;
                s[i] = 'a';
                return s;
            }
        }
        s[s.length()-1]++;
        return s;
    }
};
// @lc code=end

