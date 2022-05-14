#include <iostream>
using namespace std;

/**
 * K-th element of two sorted Arrays (Median)
 *
 * Given two sorted arr1 and arr2 of size N and M respectively and an element K.
 * The task is to find the element that would be at the k'th position of the final sorted array.
 */

class Solution{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k){
        if (k == 1) return min(arr1[0], arr2[0]);
        if (k == m + n) return max(arr1[n-1], arr2[m-1]);
        int p1 = k / 2 - 1;
        int p2 = k / 2 - 1;
        return kth(arr1, arr2, n, m, k, p1, p2);
    }

    int kth(int arr1[], int arr2[], int n, int m, int k, int p1, int p2){
        if (p1 == n-1){
            if (arr1[p1] < arr2[p2+1]){
                if ((k & 1) == 0) return max(arr1[p1], arr2[p2]);
                else return arr2[p2+1];
            }
        } else if (p2 == m-1){
            if (arr2[p2] < arr1[p1+1]){
                if ((k & 1) == 0) return max(arr1[p1], arr2[p2]);
                else return arr1[p1+1];
            }
        } else {
            if (arr1[p1] < arr2[p2+1] && arr2[p2] < arr1[p1+1]){
                if ((k & 1) == 0) return max(arr1[p1], arr2[p2]);
                else return min(arr1[p1+1], arr2[p2+1]);
            }
        }
        int diff;
        if (arr1[p1] < arr2[p2+1]){
            diff = min((n-1-p1)/2, p2/2);
            p1 += diff;
            p2 -= diff;
        } else {
            diff = min((m-1-p2)/2, p1/2);
            p1 -= diff;
            p2 += diff;
        }
        return kth(arr1, arr2, n, m, k, p1, p2);
    }
};


int main(){
    int arr1[] = {2,3,6,7,9};
    int arr2[] = {1,4,8,10};
    int k = 5;
    Solution* sol = new Solution;
    cout << sol->kthElement(arr1, arr2, 5, 4, 5) << endl;

    int arr3[] = {100,112,256,349,770};
    int arr4[] = {72,86,113,119,265,445,892};
    k = 7;
    cout << sol->kthElement(arr3, arr4, 5, 6, 7) << endl;
}
