/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string s = to_string(n);
        char top = '#';
        int cnt = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] != top){
                if (top != '#'){
                    s.push_back(cnt + '0');
                    s.push_back();
                }
                top = s[i];
                cnt = 1;
            } else {
                cnt++;
            }
        }
    }
};
// @lc code=end

