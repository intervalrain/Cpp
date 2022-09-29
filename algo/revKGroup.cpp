#include <iostream>
#include <vector>
using namespace std;

void reverseKGroup(vector<int>& nums, int k){
    int n = nums.size();
    for (int i = 0; i < n; i += k){
        int left = i, right = min(n-1, i+k-1);
        while (left < right){
            swap(nums[left++], nums[right--]);
        }
    }
}

int main(){
    cout << "n = ";
    int n;
    cin >> n;
    cout << "nums = ";
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int k;
    cout << "k = ";
    cin >> k;
    reverseKGroup(nums, k);

    for_each(nums.begin(), nums.end(), [](int x){cout << x << " ";});

    return 0;
}
