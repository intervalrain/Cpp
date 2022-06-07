#include <iostream>
#include <vector>
using namespace std;

class Solution{
public: 
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        while (m > 0 && n > 0){
            if (nums1[m-1] > nums2[n-1]){
                nums1[m+n] = nums1[--m];
            } else {
                nums1[m+n] = nums2[--n];
            }
        }
            
        while (n > 0){
            nums1[n---1] = nums2[n-1];
        }
    }
};

void printArray(vector<int>& vec){
    for (auto num : vec)
        cout << num << " ";
    cout << endl;
}

int main(){
    Solution* sol = new Solution();
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3, n = 3;
    sol->merge(nums1, m, nums2, n);
    printArray(nums1);

    delete sol;
    return 0;
}