#include <iostream>
#include <bitset>

using std::bitset;

int main(){
  bitset<16> bits(0225);
  std::cout << bits << std::endl;
  bits = ~bits;
  std::cout << bits << std::endl;
  bits = bits >> 1;
  std::cout << bits << std::endl;
  bits = bits >> 2;
  std::cout << bits << std::endl;
  bits = bits << 3;
  std::cout << bits << std::endl;

  return 0;
}
