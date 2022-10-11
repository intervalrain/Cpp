#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums, int left, int mid, int right){
    vector<int> vec;
    int i = left, j = mid+1;
    while (i <= mid && j <= right){
        int x = nums[i] < nums[j] ? nums[i++] : nums[j++];
        vec.push_back(x);
//        if (nums[i] < nums[j]){
//            vec.push_back(nums[i++]);
//        } else {
//            vec.push_back(nums[j++]);
//        }
    }
    if (i == mid + 1){
        while (j <= right){
            vec.push_back(nums[j++]);
        }
    } else if (j == right + 1){
        while (i <= mid){
            vec.push_back(nums[i++]);
        }
    }
    for (int i = left; i <= right; i++){
        nums[i] = vec[i-left];
    }
}
void sort(vector<int>& nums, int left, int right){
    if (right <= left) return;
    int mid = left + (right-left)/2;
    sort(nums, left, mid);
    sort(nums, mid+1, right);
    merge(nums, left, mid, right);
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
