#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 1,17,  5,10,13,15,10, 5,16, 8
    //
    // 0,16,-12, 5, 3, 2,-5,-5,11,-8
    // c  ^
    // ^
    //
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> diff(nums.size(), 0);
        for (int i = 1; i < diff.size(); i++){
            diff[i] = nums[i] - nums[i-1];
        }
        int right = 1, left = 0;
        int curr = diff[0];
        int res = 0;
        while (right < diff.size()){
            if (curr * diff[right] < 0){
                curr = diff[right++];
                res = max(res, right - left + 1);
            } else {
                left = right;
                curr = diff[right];
                right++;
            }
            cout << curr << " ";
        }
        return res + 1;
    }
};

int main(){
    Solution* sol = new Solution();
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    int res = sol->wiggleMaxLength(nums);

    cout << "Final Answer = " << res << endl;

    return 0;
}

