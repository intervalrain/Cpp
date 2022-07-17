#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    // 9,6,4,2,3,5,7,0,1
    // 9,7,4,2,3,5,6,0,1
    // 9,0,4,2,3,5,6,7,1
    // 0,9,4,2,3,5,6,7,1
    // 0,9,3,2,4,5,6,7,1
    // 0,9,2,3,4,5,6,7,1
    // 0,1,2,3,4,5,6,7,9
    //
    int missingNumber(vector<int>& nums){
        int n = nums.size();
        int a = 0, b = n;
        for (int i = 0; i < n; i++){
            a ^= nums[i];
            b ^= i;
        }
        return a ^ b;

        // int n = nums.size();
        // int i = 0;
        // while (i < n){
        //     if (nums[i] == n || nums[i] == i){
        //        i++;
        //     } else {
        //        swap(nums[i], nums[nums[i]]);
        //     }
        // }
        // for (int i = 0; i < n; i++){
        //     if (nums[i] != i) return i;
        // }
        // return n;

        // int n = nums.size();
        // bool map[n+1];
        // memset(map, false, sizeof(bool) * (n+1));
        // int i = 0;
        // for (i = 0; i < n; i++){
        //     map[nums[i]] = true;
        // }
        // for (i = 0; i <= n; i++){
        //     if (map[i] == false) break;
        // }
        // return i;
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
    cout << sol->missingNumber(nums) << endl;

    return 0;
}
