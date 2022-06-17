#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) return s;
        string res;
        for (int i = 0; i < s.length() - 1; i++){
            if (res.length() > 2 * (s.length() - 1 - i))
                break;
            string s1 = extend(s, i, i+1);
            string s2 = extend(s, i, i);
            if (s1.length() > res.length()) res = s1;
            if (s2.length() > res.length()) res = s2;
        }
        return res;
    }
    string extend(string s, int i, int j){
        while (i >= 0 && j < s.length()){
            if (s[i] != s[j])
                break;
            i--; j++;
        }
        return s.substr(i+1, j-i-1);
    }
};

int main(){
    Solution* sol = new Solution();
    cout << sol->longestPalindrome("babad") << endl;
    delete sol;

    return 0;
}
