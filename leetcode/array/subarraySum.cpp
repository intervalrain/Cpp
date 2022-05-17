#include <iostream>
#include <vector>
using namespace std;

/** Subarray with given sum (Easy)
 *
 * Given an unsorted array A of size N that contains only non-negative integers,
 * find a continuous sub-array which adds to a given number S.
 *
 * In case of multiple subarrays, return the subarray which comes first on moving from left to right.
 */

class Solution{
public:
    vector<int> subarraySum(int arr[], int n, long long s){
        int left = 0, right = 0;
        long long sum = 0;
        while (true){
            if (sum > s && left < n){
                sum -= arr[left++];
            } else if (sum < s && right < n){
                sum += arr[right++];
            } else {
                break;
            }
        }
        vector<int> res;
        if (sum != s){
            res.push_back(-1);
            return res;
        }
        res.push_back(left+1);
        res.push_back(right);
        return res;
    }
};


void print(vector<int> vec){
    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << (*it) << " ";
    }
    cout << endl;
}

int main(){

    Solution* sol = new Solution;
    int arr1[] = {1,2,3,7,5};
    print(sol->subarraySum(arr1, 5, 12));
    int arr2[] = {1,2,3,4,5,6,7,8,9,10};
    print(sol->subarraySum(arr2, 10, 15));
    int arr3[] = {142,112,54,69,148,45,63,158,38,60,124,142,130,179,117,36,191,43,89,107,41,143,65,49,47,6,91,130,171,151,7,102,194,149,30,24,85,155,157,41,167,177,132,109,145,40,27,124,138,139,119,83,130,142,34,116,40,59,105,131,178,107,74,187,22,146,125,73,71,30,178,174,98,113};
    print(sol->subarraySum(arr3, 74, 665));

    return 0;
}
