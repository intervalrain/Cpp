#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int main(){
  const size_t n = 6;
  int arr[n] = {0, 1, 2, 3, 4, 5};
  vector<int> ivec(arr, arr + n);

  for (vector<int>::size_type i = 0; i != ivec.size(); i++){
    std::cout << ivec[i];
  }
  return 0;
}
