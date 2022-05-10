#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string s = "";
        string dict[] = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtracking(dict, s, res, digits, 0);
        return res;
    }
    
    void backtracking(string dict[], string s, vector<string>& res, string digits, int ix){
        if (digits.length() == ix){
            res.push_back(s);
            return;
        }
        string chars = dict[digits[ix]-'0'];
        for (int i = 0; i < chars.length(); i++){
            s.push_back(chars[i]);
            backtracking(dict, s, res, digits, ix+1);
            s.pop_back();
        }      
    }
};


int main(){
    string digits = "23";
    Solution* sol = new Solution;
    vector<string> vec = sol->letterCombinations(digits);
    for (string s: vec){
        cout << s << " ";
    }
}