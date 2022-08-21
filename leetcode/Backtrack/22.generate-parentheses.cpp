/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string path;
        vector<string> res;
        backtrack(n, res, path, 0, 0);
        return res;
    }
    char parentheses[2] = {'(', ')'};
    void backtrack(int n, vector<string>& res, string& path, int left, int right){
        int m = 2*n;
        if (path.length() == m){
            res.push_back(path);
            return;
        }
        for (char c : parentheses){
            if (c == '('){
                if (left == n) continue;
                left++;
            }else if (c == ')'){
                if (right == left) continue;
                right++;
            }
            path.push_back(c);
            backtrack(n, res, path, left, right);
            path.pop_back();
            if (c == '('){
                left--;
            } else {
                right--;
            }
        }
    }
};
// @lc code=end

