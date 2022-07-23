#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    int rob(vector<int>& nums){
        if (nums.size() == 1) return nums[0];
        int res = max(nums[0], nums[1]);
        vector<int> dp(nums.size()+1);
        dp[1] = nums[0];
        dp[2] = nums[1];
        for (int i = 2; i < nums.size(); i++){
            dp[i+1] = nums[i] + max(dp[i-1], dp[i-2]);
            res = max(res, dp[i+1]);
        }
        return res;
    }
};

int main(){
    Solution* sol = new Solution();
    int n;
    cout << "n = ";
    cin >> n;
    cout << "nums = ";
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << sol->rob(nums) << endl;

    return 0;
}
