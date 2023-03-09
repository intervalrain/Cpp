#include "agtr.h"

void sort(vector<int>& nums) {
    int n = nums.size();
    for (int gap = n>>1; gap > 0; gap>>=1) {
        for (int i = gap; i < n; i++) {
            int tmp = nums[i];
            int j;
            for (j = i; j >= gap && nums[j-gap] > tmp; j -= gap) {
                nums[j] = nums[j-gap];
            }
            nums[j] = tmp;
        }
    }
}

int main() {
    agtr::judge(sort);
    return 0;
}
