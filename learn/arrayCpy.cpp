#include <iostream>

int main(){
  int array1[5] = {1,2,3,4,5};
  int array2[5] = {0};
  for (int i = 0; i < 5; i++){
    array2[i] = array1[i];
  }

  for (int i = 0; i < 5; i++){
    std::cout << array2[i] << " ";
  }
  return 0;
}
