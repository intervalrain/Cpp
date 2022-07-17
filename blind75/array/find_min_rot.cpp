#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    int findMin(vector<int>& nums){
        int left = 0, right = nums.size() - 1;
        while (left < right){
            if (nums[left] < nums[right]){
                return nums[left];
            }
            int mid = left + (right - left)/2;
            if (nums[mid] >= nums[left]){
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
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
    cout << sol->findMin(nums) << endl;

    return 0;
}
