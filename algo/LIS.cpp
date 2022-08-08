#include <bits/stdc++.h>

using namespace std;

int lbound(vector<int>& nums, int target){
    int left = 0, right = nums.size()-1;
    while (left <= right){
        int mid = left + (right - left)/2;
        if (nums[mid] >= target){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

void print(vector<int>& nums){
    for_each(nums.begin(), nums.end(), [](int x)->void{ cout << x << " ";});
    cout << endl;
}

int lengthOfLIS(vector<int> nums){
    int n = nums.size();
    vector<int> dp;
    
    int res = 1;
    for (int x : nums){
        int pos = lbound(dp, x);
        if (pos == dp.size()) dp.push_back(x);
        else dp[pos] = x;
        print(dp);
    }
    return dp.size();
}


int main(){
    vector<int> nums = {0,1,0,3,2,3};
    cout << lengthOfLIS(nums) << endl;

    return 0;
}