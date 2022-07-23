#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
  public:
    int longestCommonSubsequence(string a, string b){
        int m = a.length(), n = b.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                dp[i][j] = (a[i-1] == b[j-1]) ? (dp[i-1][j-1] + 1) : (max(dp[i][j-1], dp[i-1][j]));
            }
        }
        return dp[m][n];
    }
};

int main(){
    Solution* sol = new Solution();
    string a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    cout << sol->longestCommonSubsequence(a, b) << endl;

    return 0;
}
