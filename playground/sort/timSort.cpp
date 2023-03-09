#include "agtr.h"
#define MIN_MERGE 32

int minRunLength(int n) {
    int r = 0;
    while (n >= MIN_MERGE) {
        r |= (n & 1);
        n >>= 1;
    }
    return n + r;
}

void insertionSort(vector<int>& nums, int left, int right) {
    int n = nums.size();
    for (int i = left+1; i <= right; i++) {
        int j = i-1;
        int curr = nums[i];
        for (; j >= left; j--) {
            if (nums[j] <= curr) {
                break;
            }
            nums[j+1] = nums[j];
        }
        nums[j+1] = curr;
    }
}

void merge(vector<int>& nums, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    vector<int> tmp;
    while (i <= mid && j <= right) {
        if (nums[i] < nums[j])
            tmp.push_back(nums[i++]);
        else
            tmp.push_back(nums[j++]);
    }
    while (i <= mid)
        tmp.push_back(nums[i++]);
    while (j <= right)
        tmp.push_back(nums[j++]);
    for (i = left; i <= right; i++) {
        nums[i] = tmp[i-left];
    }
}

void sort(vector<int>& nums) {
    int minRun = minRunLength(MIN_MERGE);
    int n = nums.size();
    for (int i = 0; i < n; i += minRun) {
        int hi = min((i + MIN_MERGE - 1), n-1);
        insertionSort(nums, i, hi);
    }
    for (int size = minRun; size < n; size <<= 1) {
        for (int left = 0; left < n; left += (size << 1)) {
            int mid = left + size - 1;
            int right = min((left + (size << 1) - 1), n-1);
            if (mid < right) {
                merge(nums, left, mid, right);
            }
        }
    }
}

int main() {
    agtr::judge(sort);
    return 0;
}
