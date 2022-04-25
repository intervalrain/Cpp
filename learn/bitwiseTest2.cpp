#include <iostream>
#include <bitset>

using std::bitset;

int main(){
  bitset<30> bitset_q;
  unsigned long int_q = 0;

  bitset_q.set(3);
  int_q |= 1UL << 3;

  std::cout << bitset_q << std::endl;
  std::cout << int_q << std::endl;

  return 0;
}
