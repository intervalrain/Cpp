#include <iostream>
#include <bitset>

using namespace std;
using std::bitset;

int main(){
    
  string str("10011100");
  bitset<4> bitvec1(str);        // 1001
  bitset<8> bitvec2(str);        // 00111001
  bitset<16> bitvec3(str);       // 0011100100000000
  bitset<4> bitvec4(str, 4, 4);  // 0011
  bitset<8> bitvec5(str, 4, 4);  // 00110000
  bitset<16> bitvec6(str, 4, 4); // 0011000000000000
  bitset<16> bitvec7(str, 4);    // 0011000000000000
 
  cout << bitvec1 << endl;
  cout << bitvec2 << endl;
  cout << bitvec3 << endl;
  cout << bitvec4 << endl;
  cout << bitvec5 << endl;
  cout << bitvec6 << endl;
  cout << bitvec7 << endl;

  return 0;
}
