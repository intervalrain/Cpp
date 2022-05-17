#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Largest subarray with 0 sum (Easy)
 *
 * Given an array having both positive and negative integers.
 * The task is to compute the length of the largest subarray with sum 0.
 */

class Solution{
public:
    int maxLen(vector<int>& arr, int n){
        int res = 0, curr = 0;
        unordered_map<int,int> map;
        map[0] = 0;     // 0 could also be answer.
        for (int i = 0; i < n; i++){
            curr += arr[i];
            if (!map.count(curr)){
                map[curr] = i+1;
            } else {
                res = max(res, i-map[curr]+1);
            }
        }
        return res;
    }
};

int main(){
    Solution* sol = new Solution;
    vector<int> arr1 = {15,-2,2,-8,1,7,10,23};
    cout << sol->maxLen(arr1, 8) << endl;    // 5, {-2,2,-8,1,7}

    vector<int> arr2 = {-1,1,-1,1};
    cout << sol->maxLen(arr2, 4) << endl;    // 4

    return 0;
}
