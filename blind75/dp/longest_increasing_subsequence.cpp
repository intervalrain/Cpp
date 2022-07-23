#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        int len = 0;
        int dp[n];
        for (int x : nums){
            int left = 0, right = len;
            while (left < right){
                int mid = left + (right - left)/2;
                if (dp[mid] < x){
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            dp[left] = x;
            if (len == left) len++;
        }
        return len;
    }
};

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    cout << "nums = ";
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    Solution* sol = new Solution();
    cout << sol->lengthOfLIS(nums) << endl;

    return 0;
}
