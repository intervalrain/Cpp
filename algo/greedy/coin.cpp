#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> coinChange(vector<int>& nums, int money) {
    vector<int> res(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
        res[i] += (money / nums[i]);
        money %= nums[i];
    }
    return res;
}

vector<int> coinChange2(vector<int>& nums, int money) {
    int n = nums.size();
    vector<pair<int,vector<int>>> dp(money + 1, pair<int,vector<int>>(INT_MAX, vector<int>(n, 0)));
    dp[0] = {0, vector<int>(n, 0)};
    for (int i = nums.size()-1; i >= 0; i--) {
        for (int j = nums[i]; j <= money; j++) {
            if (dp[j].first > dp[j-nums[i]].first + 1) {
                auto cnt = dp[j-nums[i]].second;
                cnt[i]++;
                dp[j] = {dp[j-nums[i]].first + 1, cnt};
            }
        }
    }
    return dp[money].second;
    // 1069 = 1000 + 23 + 23 + 23
    //           1,0,0,0,3,0,0,0
    // 1069 = 1000 + 50 + 10 + 5 + 1 + 1 + 1 + 1
    //           1,0,0,1,0,1,1,4
}

vector<int> coinChangePlus(vector<int>&nums, int money) {
    vector<int> res;
    int coins = INT_MAX;
    for (int i = 0; i <= 4; i++) {
        vector<int> tmp = coinChange(nums, money-23*i);
        tmp[4]+=i;
        int cnt = accumulate(tmp.begin(), tmp.end(), 0);
        if (cnt < coins) {
            res = tmp;
            coins = cnt;
        }
    }
    return res;
}

int main(){
    int money = 0;
    cin >> money;
    vector<int> nums = {1000, 500, 100, 50, 23, 10, 5, 1};
    vector<int> res = coinChange(nums, money);
    vector<int> res2 = coinChange2(nums, money);
    vector<int> res3 = coinChangePlus(nums, money);

    for_each(res.begin(), res.end(), [](int x) { cout << x << " "; });
    cout << endl;
    for_each(res2.begin(), res2.end(), [](int x) { cout << x << " "; });
    cout << endl;
    for_each(res3.begin(), res3.end(), [](int x) { cout << x << " "; });

    return 0;
}
