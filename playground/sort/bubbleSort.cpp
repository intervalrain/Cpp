#include "agtr.h"

void sort(vector<int>& nums) {
    int n = nums.size();
    for (int i = n-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j+1]) swap(nums[j], nums[j+1]);
        }
    }
}

int main(){
    agtr::judge(sort);
    return 0;
}
