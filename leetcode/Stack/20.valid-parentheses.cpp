/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s){
            if (isLeft(c)){
                st.push(c);
            } else {
                if (st.empty()) return false;
                if (!isMatch(st.top(), c)) return false;
                st.pop();
            }
        }
        return st.empty();
    }
    bool isLeft(char c){
        return c == '(' || c == '[' || c == '{';
    }
    bool isMatch(char left, char right){
        if (left == '(' && right == ')') return true;
        else if (left == '{' && right == '}') return true;
        else if (left == '[' && right == ']') return true;
        return false;
    }
};
// @lc code=end

