#include <iostream>
using namespace std;

int main(){
  int x = 0;
  cin >> x;
  int* array = new int[x];
  if (x <= 2)
    return 0;
  array[0] = 1;
  array[1] = 1;

  for (int i = 2; i < x; ++i){
    array[i] = array[i-1] + array[i-2];
  }
  

  for (int i = 0; i < x; ++i){
    cout << array[i] << " ";
  }

  return 0;
}
