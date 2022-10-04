#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int len = 0, left = 0, right = 0;
        vector<string> res;
        while (right < words.size()){
            string s = words[right++];
            int gap = right-left-1;
            if (len + s.length() + gap == maxWidth){
                res.push_back(bloom(words, left, right, maxWidth, len+s.length()));
                len = 0;
                left = right;
            } else if (len + s.length() + gap > maxWidth){
                res.push_back(bloom(words, left, right-1, maxWidth, len));
                len = s.length();
                left = right - 1;
            } else {
                len += s.length();
            }
        }
        if (right-left > 0){
            string tmp;
            for (int i = left; i < right; i++){
                tmp = tmp + words[i] + " ";
            }
            tmp = tmp.substr(0, tmp.length()-1);
            tmp += string(maxWidth - tmp.length(), ' ');
            res.push_back(tmp);
        }
        return res;
    }
    string bloom(vector<string>& words, int left, int right, int w, int len){
        int n = right - left - 1;
        if (n == 0){
            return words[left] + string(w - words[left].length(), ' ');
        }
        int blank = (w - len)/ n;
        int extra = w - len - n * blank;
        string res;
        for (int i = left; i < right-1; i++){
            int e = (extra-- > 0) ? 1 : 0;
            res += (words[i] + string(blank + e, ' '));
        }
        return res + words[right-1];
    }
};
// @lc code=end

