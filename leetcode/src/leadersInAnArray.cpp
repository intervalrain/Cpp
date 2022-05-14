#include <iostream>
#include <vector>
using namespace std;

/**
 * Leaders in an array (Easy)
 *
 * Given an array A of positive integers.
 * Your task is to find the leaders in the array.
 * An element of array is leader if it is greater than or equal to all the elements to its right side.
 * The rightmost element is always a leader
 */


// Example1:
// n = 6;
// A[] = {16, 17, 4, 3, 5, 2}
//             ^        ^  ^
// answer: 17 5 2

void print(vector<int> vec){
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

class Solution{
    public:
    vector<int> leaders(int a[], int n){
        int max = a[n-1];
        vector<int> res;
        for (int i = n-1; i >= 0; i--){
            if (a[i] >= max){
                max = a[i];
                res.push_back(a[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){

    Solution* sol = new Solution;
    int a[] = {16,17,4,3,5,2};
    print(sol->leaders(a, 6));  // 17, 5, 2
    int b[] = {1,2,3,4,0};
    print(sol->leaders(b, 5));  // 4, 0

}
