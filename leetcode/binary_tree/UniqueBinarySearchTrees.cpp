#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    int numTrees(int n){
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        int cnt = 0;
        for (int i = 2; i <= n; i++){
            for (int j = 0; j < i; j++){
                dp[i] += dp[j]*dp[i-j-1];
                cout << (++cnt) << " ";
            }
        }
        return dp[n];
    }
};


int main(){
    Solution* sol = new Solution();
    int n;
    cin >> n;
    cout << sol->numTrees(n);

    return 0;
}
