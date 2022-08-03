#include <iostream>
#include <vector>

using namespace std;

int binarySeacrh(vector<int> nums, int target){
    int left = 0, right = nums.size()-1;
    while (left <= right){
        int mid = left + (right-left)/2;
        if (nums[mid] == target){
            return mid;
        } else if (nums[mid] < target){
            right = mid - 1;
        } else {
            left = mid + 1
        }
    }
    return -1;
}

int lower_bound(vector<int> nums, int target){
    int left = 0, right = nums.size()-1;
    while (left <= right){
        int mid = left + (right-left)/2;
        if (nums[mid] == target){
            right = mid - 1;
        } else if (nums[mid] < target){
            right = mid - 1;
        } else {
            left = mid + 1
        }
    }
    return left;
}

int upper_bound(vector<int> nums, int target){
    int left = 0, right = nums.size()-1;
    while (left <= right){
        int mid = left + (right-left)/2;
        if (nums[mid] == target){
            left = mid + 1;
        } else if (nums[mid] < target){
            right = mid - 1;
        } else {
            left = mid + 1
        }
    }
    return right;
}