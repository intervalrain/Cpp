#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
    vector<int> nums;
    nums.push_back(-4);
    nums.push_back(-1);
    nums.push_back(-0);
    nums.push_back(3);
    nums.push_back(10);

    vector<int> res(nums.size());
    int pivot = 0;
    for (int i = nums.size() - 1; i >= 0; --i){
        if (nums[i] < 0){
            pivot = i;
            break;
        }
    }

    int neg = pivot;
    int pos = pivot + 1;

    for (int i = 0; i < nums.size(); ++i){
        int pos_value = INT_MAX;
        int neg_value = INT_MAX;

        if (pos < nums.size()){
            pos_value = nums[pos] * nums[pos];
        }
        if (neg >= 0){
            neg_value = nums[neg] * nums[neg];
        }
        if (pos_value < neg_value){
            res[i] = pos_value;
            pos++;
        } else {
            res[i] = neg_value;
            neg--;
        }
    }


    // vector<int> res(nums.size(), 0);
    // int left = 0;
    // int right = nums.size()-1;
    // int cnt = right;
    // while (left <= right){
    //     int r = nums.at(right)*nums.at(right);
    //     int l = nums.at(left)*nums.at(left);
    //     if (r > l){
    //         res.at(cnt) = r;
    //         right --;
    //     } else {
    //         res.at(cnt) = l;
    //         left++;
    //     }
    //     cnt--;
    // }

    for (int idx = 0; idx < res.size(); idx++){
        cout << res.at(idx) << ", ";
    }
    
}
