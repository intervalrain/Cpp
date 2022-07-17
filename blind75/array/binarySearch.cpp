#include <iostream>
#include <vector>
#include "snippet.cpp"

using namespace std;

class Solution{
public:
    int binarySearch(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (nums[mid] == target){
                return mid;
            } else if (nums[mid] < target){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main(){
    Solution* sol = new Solution();
    vector<int> nums;
    input(nums);

    int target;
    cout << "target = ";
    cin >> target;

    cout << sol->binarySearch(nums, target) << endl;

    return 0;
}
