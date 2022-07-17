#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    int maxProduct(vector<int>& nums){
        int res = INT_MIN;
        int min_neg = 0;
        int prod = 1;
        for (int i = 0; i < nums.size(); i++){
            prod *= nums[i];
            res = max(res, prod);
            if (prod == 0){
                prod = 1;
                min_neg = 0;
            } else if (prod < 0){
                if (min_neg == 0){
                    min_neg = prod;
                } else {
                    res = max(res, prod/min_neg);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution* sol = new Solution();
    int n;
    cout << "n =";
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << sol->maxProduct(nums) << endl;

    return 0;
}

