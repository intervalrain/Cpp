#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int> nums){
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n-2 ; i++){
            if (nums[i] > 0) break;
            int j = i + 1;
            int k = n - 1;
            while (j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0){
                    vector<int> vec = {nums[i], nums[j], nums[k]};
                    res.push_back(vec);
                    j++;
                    while (nums[j] == nums[j-1]){
                        j++;
                    }
                }
                else if (sum < 0){
                    j++;
                } else {
                    k--;
                }
            }
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
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<vector<int>> res = sol->threeSum(nums);
    for (vector<int> vec:res){
        for (int v:vec){
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
