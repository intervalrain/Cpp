#include "shuffle.h"
#include "imath.h"
#include <iostream>

using namespace std;

void print(vector<int> vec){
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main(){
    vector<int> nums1 = {2,5,4,1,7};
    vector<int> nums2 = {5,1,2,4,3};
    

    int sum = alg::dot_product(nums1, nums2);

    cout << sum << endl;

    // print(nums1)

    // alg::shuffle(nums);


    

    return 0;
}