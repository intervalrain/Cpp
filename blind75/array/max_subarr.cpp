#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxSubArray(vector<int>& nums){
        int res = INT_MIN;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++){
            curr = curr < 0 ? nums[i] : nums[i] + curr;
            res = max(res, curr);
        }
        return res;
    }
};

int main(){
    Solution* sol = new Solution();
    int n;
    cout << "n = ";
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << sol->maxSubArray(nums) << endl;

    return 0;
}
