#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int coinChange(vector<int>& coins, int amount){
        if (amount == 0) return 0;
        sort(coins.begin(), coins.end());
        reverse(coins.begin(), coins.end());
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0
        for (int coin:coins){
            for (int i = coin; i <= amount; i++){
                if (dp[i-coin] == INT_MAX)
                    continue;
                else
                    dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main(){
    Solution sol;
    int arr[] = {2};
    vector<int> coins(arr, arr+1);
    cout << sol.coinChange(coins, 1) << endl;

    return 0;
}
