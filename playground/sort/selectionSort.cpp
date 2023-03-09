#include "agtr.h"

void sort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n-1; i++) {
        int p = i;
        for (int j = i+1; j < n; j++) {
            if (nums[j] < nums[p]) p = j;
        }
        swap(nums[p], nums[i]);
    }
}

int main() {
    agtr::judge(sort);
    return 0;
}
