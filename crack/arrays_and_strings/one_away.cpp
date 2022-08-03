#include <iostream>
#include <vector>
#include <cmath>

/**
 * There are three types of edits that can be performed on strings:
 *   1. insert a character
 *   2. remove a character
 *   3. replace a character
 * Given two strings, write a function to check if they are one edit (or zero edits) away.
 */

using namespace std;

int min(int a, int b, int c){
    int tmp = min(a, b);
    return min(tmp, c);
}

class Solution{
  public:
//    bool one_away(string s, string t){
//        return no_away(s, t) <= 1;
//    }

    bool one_erase(string s, string t){
        // s is the longer one
        int i = 0, j = 0;
        bool flag = false;
        while (i < s.length()){
            if (s[i] != t[j]){
                if (!flag){
                    flag = true;
                    i++;
                } else {
                    return false;
                }
            } else {
                i++;
                j++;
            }
        }
        return true;
    }

    bool one_away(string s, string t){
        if (abs((int)s.length()-(int)t.length()) > 1){
            return false;
        } else if (s.length() == t.length()){
            int i = 0;
            int cnt = 0;
            while (i < s.length()){
                if (s[i] != t[i]) cnt++;
                i++;
            }
            return cnt <= 1;
        } else if (s.length() - t.length() == 1){
            return one_erase(s, t);
        } else {
            return one_erase(t, s);
        }
    }




    int no_away(string s, string t){
        int m = s.length(), n = t.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i <= m; i++){
            for (int j = 0; j <= n; j++){
                if (i == 0 && j == 0){
                    dp[i][j] = 0;
                } else if (i == 0){
                    dp[i][j] = j;
                } else if (j == 0){
                    dp[i][j] = i;
                } else if (s[i-1] == t[j-1]){
                    dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]);
                } else {
                    dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    Solution* sol = new Solution();
    while (true){
        cout << "Please inupt two strings to check if it is one_away(q to quit): ";
        string s;
        cin >> s;
        if (s[0] == 'q' || s[0] == 'Q') break;
        string t;
        cin >> t;
        cout << (sol->one_away(s, t) ? "yes" : "no") << endl;
    }

    return 0;
}
