#include "agtr.h"

int partition(vector<int>& nums, int left, int right) {
    int pivot = left;
    int i = left;
    int j = right+1;
    while (true) {
        while (i < right && nums[++i] < nums[pivot]);
        while (j > left && nums[--j] > nums[pivot]);
        if (i >= j) break;
        swap(nums[i], nums[j]);
    }
    swap(nums[pivot], nums[j]);
    return j;
}

void sort(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int pivot = partition(nums, left, right);
    sort(nums, left, pivot-1);
    sort(nums, pivot+1, right);
}

void sort(vector<int>& nums) {
    sort(nums, 0, nums.size()-1);
}

int main() {
    agtr::judge(sort);
    return 0;
}
