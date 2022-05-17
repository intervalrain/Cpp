#include <iostream>
#include <vector>
using namespace std;

/**
 * Stock buy and sell (Medium)
 *
 * The cost of stock on each day is given in an array arr of size n.
 * Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.
 * Note: There may be multiple possible solutions.
 * Return any one of them.
 * Any correct solution will result in an output of 1,
 * whereas wrong solutions will result in an output of 0.
 */

class Solution{
public:
    vector<vector<int> > stockBySell(vector<int> arr, int n){
        vector<vector<int> > res;
        vector<int> comb;
        int i = 0;
        while (i < n){
            while (i < n - 1 && arr[i] >= arr[i+1]){
                i++;
            }
            comb.push_back(i++);
            while (i < n - 1 && arr[i] <= arr[i+1]){
                i++;
            }
            if (i != n)
                comb.push_back(i++);
            if (comb.size() == 2){
                res.push_back(comb);
                comb.clear();
            }
        }
        return res;
    }
};

void print(vector<vector<int> > vec){
    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << "(" << (*it)[0] << "," << (*it)[1] << ")" << endl;
    }
}

int main(){
    Solution* sol = new Solution;
    vector<int> arr1 = {100,180,260,310,40,535,695};
    print(sol->stockBySell(arr1, 7));    // (0,3),(4,6)
    cout << endl;

    vector<int> arr2 = {4,2,2,2,4};
    print(sol->stockBySell(arr2, 5));    // (3,4)
    cout << endl;

    vector<int> arr3 = {11,42,49,96,23,20,49,26,26,18,73,2,53,59,34,99,25,2};
    print(sol->stockBySell(arr3, 18));
    cout << endl;

}
