#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(vector<int>& nums) {
    for (auto it = nums.begin(); it != nums.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int left_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left)/2;
        if (nums[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
int right_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left)/2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left - 1;
}

int main(){
    vector<int> nums = {-3,-2,-1,0,0,0,0,1,2,3};
    printArray(nums);
    auto itl = lower_bound(nums.begin(), nums.end(), 0);
    auto itr = upper_bound(nums.begin(), nums.end(), 0);
    cout << "lower_bound = " << distance(nums.begin(), itl) << endl;
    cout << "upper_bound = " << distance(nums.begin(), itr) << endl;

    cout << "left_bound = " << left_bound(nums, 0) << endl;
    cout << "right_bound = " << right_bound(nums, 0) << endl;

    return 0 ;
}
