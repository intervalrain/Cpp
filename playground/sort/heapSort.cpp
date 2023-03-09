#include "agtr.h"

void heapify(vector<int>& nums, int i) {
    int left = 2*i+1;
    int right = 2*i+2;
    int p = i;
    int n = nums.size();
    if (left < n && nums[left] < nums[p]) p = left;
    if (right < n && nums[right] < nums[p]) p = right;
    if (p != i) {
        swap(nums[i], nums[p]);
        heapify(nums, p);
    }
}
void sort(vector<int>& nums) {
    vector<int> vec(nums.begin(), nums.end());
    int n = vec.size();
    int parent = (n-1)/2;
    for (int i = parent; i >= 0; i--) {
        heapify(vec, i);
    }

    for (int i = 0; i < n; i++) {
        nums[i] = vec[0];
        vec[0] = vec.back();
        vec.pop_back();
        heapify(vec, 0);
    }
}

int main() {
    agtr::judge(sort);
    return 0;
}
