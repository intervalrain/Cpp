#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while (left < right){
            while (left < right && !isAlphabet(s[left])) left++;
            while (right > left && !isAlphabet(s[right])) right--;
            if (isUppercase(s[left])) s[left] = s[left] - 'A' + 'a';
            if (isUppercase(s[right])) s[right] = s[right] - 'A' + 'a';
            if (s[left] != s[right]) {
                cout << left << " " << right << endl;
                cout << s[left] << " " << s[right] << endl;
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool isAlphabet(char c){
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    bool isUppercase(char c){
        return (c >= 'A' && c <= 'Z');
    }
};
// @lc code=end

// "A man, a plan, a canal: Panama"
//       ^
//                           ^
//

