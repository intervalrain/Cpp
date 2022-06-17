#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    int minDistance(string word1, string word2){
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp (m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return m + n - 2 * dp[m][n];
    }
};

int main(){
    string word1 = "peace";
    string word2 = "ease";
    Solution* sol = new Solution();
    cout << sol->minDistance(word1, word2) << endl;
    delete sol;
}