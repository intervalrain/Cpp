#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    vector<int> countBits(int n){
        if (n == 0) return {0};
        if (n == 1) return {0,1};
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        int j = 2;
        int cnt = j;
        vector<int> res = {0,1};
        for (int i = 2; i <= n; i++){
            if (cnt == 0){
                j <<= 1;
                cnt = j;
            }
            dp[i] = 1 + dp[i-j];
            res.push_back(dp[i]);
            cnt--;
        }

        return res;
    }
};

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    Solution* sol = new Solution();
    vector<int> vec = sol->countBits(n);
    for (int i = 0; i <= n; i++){
        cout << vec[i] << " ";
    }
    cout << endl;


    return 0;
}
