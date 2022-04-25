#include <iostream>
#include <cmath>

int main(){
  for (int i = 0; i < 100; i++){
    float f = sqrt(i);
    std::cout << f << " " << f * f; 
    if (f*f != i){
      std::cout << "!!!";
    }
    std::cout << std::endl;
  }
  return 0;
}
