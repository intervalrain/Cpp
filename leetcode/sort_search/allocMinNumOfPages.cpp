#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Allocate minimum number of pages(Hard)
 *
 * You are given n number of books.
 * Every ith book has a_i number of pages.
 *
 * You have to allocate contiguous books to m number of students.
 * There can be many ways or permutations to do so.
 * In each permutation, one of the m students will be allocatied the maximum number of pages.
 * Out of all these permutations, the task is to find that particular permutation in which
 * the maximum number of pages allocated to a student is the minimum of those in all the other permutations and
 * print this minimum value.
 *
 * Each book will be allocated to exactly one student.
 * Each student has to be allocated at least one book.
 *
 * Note: Return -1 if a valid assignment is not possible,
 * and allotment should be in contiguous order (see the explanation for better understanding).
 */

class Solution{
public:
    bool isValid(int arr[], int n, int m, int curr){
        int stu = 1;
        int sum = 0;
        for (int i = 0; i < n; i++){
            if (arr[i] > curr)
                return false;
            if (sum + arr[i] > curr){
                stu++;
                sum = arr[i];
                if (stu > m) return false;
            } else {
                sum += arr[i];
            }
        }
        return true;
    }
    int findPages(int arr[], int n, int m){
        int sum = 0;
        if (n < m) return -1;
        for (int i = 0; i < n; i++){
            sum += arr[i];
        }
        int start = 0, end = sum;
        int res = INT_MAX;

        while (start <= end){
            int mid = (start + end)/2;
            if (isValid(arr, n, m, mid)){
                res = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return res;
    }
};

int main(){
    Solution* sol = new Solution;
    int arr1[] = {12,34,67,90};
    cout << sol->findPages(arr1, 4, 2) << endl; // 113

    int arr2[] = {15,17,20};
    cout << sol->findPages(arr2, 3, 2) << endl; // 32
}
