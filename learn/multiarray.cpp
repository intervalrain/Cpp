#include <iostream>

using namespace std;

int main(){
  int ia1[3][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11}};
  int ia2[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
  int ia3[3][4] = {{0},{4},{8}};
  int ia4[3][4] = {0,3,6,9};

  for (int i = 0; i < 3; i++){
    for (int j = 0 ; j < 4; j++){
      cout << ia3[i][j] << " ";
    }
    cout << endl;
  }
}