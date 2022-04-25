#include <iostream>
using namespace std;

int main(){
  int array[] = {1, 2, 3};
  int len = sizeof(array)/sizeof(array[0]);
  for (int i = 0; i < len; i++){
    cout << array[i] << " ";
  }
  cout << endl;

  return 0;
}
