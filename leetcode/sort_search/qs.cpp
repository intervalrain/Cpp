#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int partition(vector<int>& arr, int low, int high){
        int pi = high;
        int ix = low;
        for (int i = low; i < high; i++){
            if (arr[pi] > arr[i]){
                swap(arr[i], arr[ix]);
                ix++;
            }
        }
        swap(arr[ix], arr[pi]);
        return ix;
    }

    void quickSort(vector<int>& arr, int low, int high){
        if (low >= high) return;
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
    void sort(vector<int>& arr, int n){
        quickSort(arr, 0, n-1);
    }
};


void print(vector<int> vec){
    for (auto it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";
    cout << endl;
}

int main(){
    int arr[] = {2,1,6,8,4,3,9,7,5};
    vector<int> vec(arr, arr+9);
    print(vec);

    Solution* sol = new Solution;
    sol->sort(vec, vec.size());
    print(vec);   
}