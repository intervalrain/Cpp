#include <iostream>
#include <unordered_set>
using namespace std;

/**
 * Swapping pairs make sum equal (Easy)
 *
 * Given twe arrays of integers a[] and b[] of size n and m,
 * the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will
 * make the sum of two arrays equal.
 */

class Solution{
public:
    int findSwapValues(int a[], int n, int b[], int m){
        int suma = 0, sumb = 0;
        unordered_set<int> set;

        for (int i = 0; i < n; i++){
            suma += a[i];
        }
        for (int i = 0; i < m; i++){
            sumb += b[i];
            set.insert(b[i]);
        }
        int target = (sumb - suma);
        if ((abs(target) & 1) == 1 ) return -1;
        else target /= 2;

        for (int i = 0; i < n; i++){
            if (set.count(target + a[i])) return 1;
        }
        return -1;
    }
};

int main(){
    Solution* sol = new Solution;
    int n, m;
    int a1[] = {4,1,2,1,1,2};
    int b1[] = {3,6,3,3};
    n = sizeof(a1)/sizeof(int);
    m = sizeof(b1)/sizeof(int);
    cout << sol->findSwapValues(a1, n, b1, m);

    int a2[] = {5,7,4,6};
    int b2[] = {1,2,3,8};
    n = sizeof(a2)/sizeof(int);
    m = sizeof(b2)/sizeof(int);
    cout << sol->findSwapValues(a2, n, b2, m);

    return 0;
}
