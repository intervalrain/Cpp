#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& arr){
    int MOD = (int)(1e9)+7;
    sort(arr.begin(), arr.end());  // 2, 4, 5     nlogn
    unordered_map<int, int> dp;                   // n
    int cnt = 0;
    for (int x : arr){      // [2,1],[4,2],[5,1],[10,3]
        for (auto m : dp){
            if (dp.count(x/m.first) && (x/m.first)*(m.first) == x){  // 9/2 * 2 = 8
                if (x/m.first == m.first){
                    dp[x] += (dp[m.first]*dp[m.first] % MOD);
                } else {
                    dp[x] += (dp[x/m.first]*dp[m.first] % MOD);
                }
            }
        }
        dp[x]++;
        cnt = ((cnt + dp[x]) % MOD);
    }
    return cnt % MOD;
}

int main(){
    vector<int> nums = {45,42,2,18,23,1170,12,41,40,9,47,24,33,28,10,32,29,17,46,11,759,37,6,26,21,49,31,14,19,8,13,7,27,22,3,36,34,38,39,30,43,15,4,16,35,25,20,44,5,48};
//    sort(nums.begin(), nums.end());

    cout << solve(nums);
    return 0;
}
