#include "agtr.h"

void merge(vector<int>& nums, int left, int mid, int right) {
    int i = left, j = mid + 1;
    vector<int> tmp;
    while (i <= mid && j <= right) {
        if (nums[i] < nums[j])
            tmp.push_back(nums[i++]);
        else
            tmp.push_back(nums[j++]);
    }
    while (i <= mid) tmp.push_back(nums[i++]);
    while (j <= right) tmp.push_back(nums[j++]);
    for (i = left; i <= right; i++) {
        nums[i] = tmp[i-left];
    }
}

void sort(vector<int>& nums, int left, int right) {
    if (right <= left) return;
    int mid = left + (right-left)/2;
    sort(nums, left, mid);
    sort(nums, mid+1, right);
    merge(nums, left, mid, right);
}

void sort(vector<int>& nums) {
    sort(nums, 0, nums.size()-1);
}

int main() {
    agtr::judge(sort);
    return 0;
}
