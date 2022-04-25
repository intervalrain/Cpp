#include <iostream>

int main(){
  double pi = 3.14159265;
  double pi2 = 3.14;

  double *ptr = &pi;
  double *ptr2 = &pi2;

  

  std::cout << *ptr << std::endl;
  
  return 0;
}
