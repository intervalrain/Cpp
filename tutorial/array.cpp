#include <iostream>
using namespace std;

int main(){
    int nums[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

    for (int i = 0; i < sizeof(nums)/sizeof(int); ++i){
        cout << nums[i] << " ";
    }

    return 0;
}
