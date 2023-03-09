#include "agtr.h"

void sort(vector<int>& nums) {
    vector<int> dp(10, 0);
    for (const auto& x : nums) {
        dp[x]++;
    }
    int j = 0;
    for (int i = 0; i < 10; i++) {
        while (dp[i]-- > 0) {
            nums[j++] = i;
        }
    }
}

int main() {
    agtr::judge(sort);
    return 0;
}
