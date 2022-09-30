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
        vector<vector<string>> lines;
        vector<string> line;
        vector<int> lens;
        int len = 0;
        for (int i = 0; i < words.length(); i++){
            if (len + words[i].length() + line.size() > maxWidth){
                lines.push_back(line);
                lens.push_back(len);
                line.clear();
                line.push_back(words[i]);
                len = words[i].length();
            } else if (len + words[i].length() + line.size() == maxWidth){
                line.push_back(words[i]);
                lines.push_back(line);
                lens.push_back(len + words[i].length());
                line.clear();
                len = 0;
            } else if (len + words[i].length() + line.size() < maxWidth){
                line.push_back(words[i]);
                len += words[i].length();
            }
        }
        if (line.size() > 0){
            lines.push_back(line);
            lens.push_back(len);
            line.clear();
        }

        for (int i = 0; i < lines.size(); i++){
            string s;
            
        }
    }
};
// @lc code=end


