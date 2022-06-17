#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int n = s.length();
        for (int len = n; len >= 1; len--){
            for (int pos = 0; pos + len <= n; pos++){
                if (isPalindrome(s, pos, pos + len - 1))
                    return s.substr(pos, len);
            }
        }
        return "";
    }
    bool isPalindrome(string s, int left, int right){
        while (left < right){
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
};

int main(){
    Solution* sol = new Solution();
    cout << sol->longestPalindrome("babad") << endl;
    delete sol;

    return 0;
}
