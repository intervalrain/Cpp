#include <iostream>

int main(){
  const size_t n = 5;
  int arr[n] = {1,2,3,4,5};
  for (int *pb = arr, *pe = arr + n; pb != pe; ++pb){
    std::cout << *pb << ' ';  
  }
  return 0;
}
