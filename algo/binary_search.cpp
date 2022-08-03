#include <iostream>
#include <vector>

using namespace std;

int lower_bound(vector<int> nums, int target){
    int left = 0, right = nums.size()-1;
    while (left <= right){
        int mid = left + (right-left)/2;
        if (nums[mid] < target){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
int upper_bound(vector<int> nums, int target){
    int left = 0, right = nums.size()-1;
    while (left <= right){
        int mid = left + (right-left)/2;
        if (nums[mid] > target){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
int binary_search(vector<int> nums, int target){
    int left = 0, right = nums.size()-1;
    while (left <= right){
        int mid = left + (right-left)/2;
        if (nums[mid] == target){
            return mid;
        } else if (nums[mid] >= target){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}


int main(){
    vector<int> nums = {1,1,2,3,3,3,3,3,4,5,5};
    for (int x : nums) cout << x << " ";
    cout << "\ninput: 3, 0, 6" << endl;
    cout << "binary_search: " << endl;
    cout << binary_search(nums, 3) << endl;
    cout << binary_search(nums, 0) << endl;
    cout << binary_search(nums, 6) << endl;

    cout << "lower_bound: " << endl;
    cout << lower_bound(nums, 3) << endl;
    cout << lower_bound(nums, 0) << endl;
    cout << lower_bound(nums, 6) << endl;

    cout << "upper_bound: " << endl;
    cout << upper_bound(nums, 3) << endl;
    cout << upper_bound(nums, 0) << endl;
    cout << upper_bound(nums, 6) << endl;

    return 0;
}
