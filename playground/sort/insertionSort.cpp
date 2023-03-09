#include "agtr.h"

void sort(vector<int>& nums){
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        int j = i-1;
        int curr = nums[i];
        for (; j >= 0; j--) {
            if (nums[j] <= curr) {
                break;
            }
            nums[j+1] = nums[j];
        }
        nums[j+1] = curr;
    }
}

int main(){
    agtr::judge(sort);
    return 0;
}
