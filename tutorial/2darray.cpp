#include <iostream>
using namespace std;

int main(){
    int nums[3][2] = {
                    {1, 2},
                    {3, 4},
                    {5, 6}
                          };
    // nested loop
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
