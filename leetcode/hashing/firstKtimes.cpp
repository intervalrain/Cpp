#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * First element to occur k times (Basic)
 *
 * Given an an array of n integers.
 * Find the first element that occurs alleast K number of times.
 */

class Solution{
public:
    int firstElementKTime(int arr[], int n, int k){
        unordered_map<int,int> map;
        for (int i = 0; i < n; i++){
            map[arr[i]]++;
            if (map[arr[i]] == k){
                return arr[i];
            }
        }
        return -1;
    }
};

int main(){
    Solution* sol = new Solution;
    int n = 7;
    int k = 2;
    int arr[] = {1,7,4,3,4,8,7};

    cout << sol->firstElementKTime(arr, n, k) << endl;

    return 0;
}
