#include <iostream>
#include <cmath>

int main(){
  for (int i = 0; i < 100; i++){
    float f = sqrt(i);
    std::cout << f << " " << f * f << std::endl;
  }
  return 0;
}
