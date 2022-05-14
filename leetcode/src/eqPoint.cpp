#include <iostream>
#include <vector>
using namespace std;

/**
 * Equilibrium point (Easy)
 * Given an array A of n positive numbers.
 * The task is to find the first Equilibrium Point in the array.
 * Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
 *
 * Note: Return the index of Equilibrium point. (1-based index)
 *
 */

// Example1
// n = 5
// A[] = {1,3,5,2,2}
// answer = 3

class Solution{
    public:
    int equilibriumPoint(vector<int> a, int n){
        if (n == 1) return 1;
        int l = 0, r = n - 1;
        while (l+1 < r){
            if (a[l] < a[r]){
                a[l+1] += a[l];
                l++;
            } else {
                a[r-1] += a[r];
                r--;
            }
        }
        if (a[l] == a[r+1]) return l+2;
        if (a[l-1] == a[r]) return l+1;
        return -1;
    }
};

int main(){
    vector<int> A = {1,3,5,2,2};
    Solution* sol = new Solution;
    cout << sol->equilibriumPoint(A, 5) << endl;  // 3

    vector<int> B = {1};
    cout << sol->equilibriumPoint(B, 1) << endl;  // 1

    vector<int> C = {20,17,42,25,32,32,30,32,37,9,2,33,31,17,14,40,9,12,36,21,8,33,6,6,10,37,12,26,21,3};
    cout << sol->equilibriumPoint(C, 30) << endl;  // 13

    return 0;
}



