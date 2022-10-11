#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& nums, int left, int right){
    int pivot = right;
    while (left < right){
        while (nums[left] < nums[pivot]) left++;
        while (nums[right] > nums[pivot]) right--;
        if (left < right) swap(nums[left], nums[right]);
    }
    return pivot;
}

void sort(vector<int>& nums, int left, int right){
    if (left >= right) return;
    int mid = partition(nums, left, right);
    sort(nums, left, mid-1);
    sort(nums, mid+1, right);
}

void sort(vector<int>& nums){
    sort(nums, 0, nums.size()-1);
}

int main(){
    vector<int> nums = {2,8,9,4,1,7,3,5,6};
    sort(nums);

    for_each(nums.begin(), nums.end(), [](int x){cout << x << " ";});

    return 0;
}
