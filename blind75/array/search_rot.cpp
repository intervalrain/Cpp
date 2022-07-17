#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    int search(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (nums[mid] == target){
                return mid;
            } else if (nums[mid] >= nums[left]){
                if (target < nums[mid] && target >= nums[left]){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[right]){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
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
    int target;
    cout << "target = ";
    cin >> target;

    cout << sol->search(nums, target) << endl;

    return 0;
}
