#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    void reverseInGroups(vector<long long>& arr, int n, int k){
        auto it = arr.begin();
        int l = 0, r = min(n, k);
        while (r <= n && l <= n){
            reverse(it + l, it + r);
            l += k;
            r = min(n, r + k);
        }
    }
};

int main(){
    vector<long long> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    int n = arr.size(), k = 3;
    
    Solution* sol = new Solution;
    sol->reverseInGroups(arr, n, k);
    for (int i : arr) 
        cout << i << " ";
    cout << endl;

}