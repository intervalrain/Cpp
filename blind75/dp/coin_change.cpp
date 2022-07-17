#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    int coinChange(vector<int>& coins, int amount){
        vector<int> dp(amount+1, 10005);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++){
            int coin = coins[i];
            for (int j = coin; j <= amount; j++){
                dp[j] = min(dp[j], dp[j-coin] + 1);
            }
        }
        return dp[amount] >= 10005 ? -1 : dp[amount];
    }
    // 0 1 2 3 4 5 6 7 8 9 10 11
    // 0 1 2 3 4 5 6 7 8 9 10 11
    // 0 1 2 3 4 1 2 3 4 5  2  3
    // 0 1 1 2 2 1 2 3 4 5  2  6
};

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    vector<int> nums (n, 0);
    cout << "nums = ";
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int amount;
    cout << "amount = ";
    cin >> amount;
    Solution* sol = new Solution();
    cout << sol->coinChange(nums, amount) << endl;

    return 0;
}
