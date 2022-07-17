#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    vector<int> productExceptSelf(vector<int>& nums){
        int zeros = 0;
        int prod = 1;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                zeros++;
            } else {
                prod *= nums[i];
            }
            if (zeros == 2) break;
        }

        for (int i = 0; i < nums.size(); i++){
            if (zeros == 1){
                nums[i] = nums[i] == 0 ? prod : 0;
            } else if (zeros == 2){
                nums[i] = 0;
            } else {
                nums[i] = prod/nums[i];
            }
        }
        return nums;
    }
};

int main(){
    Solution* sol = new Solution();
    int n;
    cout << "n = ";
    cin >> n;
    vector<int> nums(n, 0);
    cout << "nums = ";
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<int> res = sol->productExceptSelf(nums);
    for (int i = 0; i < n; i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
