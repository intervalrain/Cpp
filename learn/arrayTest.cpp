#include <iostream>

int main(){
  int staff_size = 3;
  int salaries[staff_size];

  salaries[0] = 63000;
  salaries[1] = 85000;
  salaries[2] = 96000;

  for (unsigned int idx = 0; idx != 3; ++idx){
    std::cout << salaries[idx] << std::endl;
  }

  return 0;
}
