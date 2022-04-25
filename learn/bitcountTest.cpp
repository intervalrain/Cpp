#include <iostream>
#include <bitset>
#include <string>

using std::bitset;
using std::string;
using namespace std;

int main(){

  string svec("10011100");
  bitset<8> b(svec);

  cout << b << endl;  
  cout << b.any() << endl;
  cout << b.none() << endl;
  cout << b.count() << endl;
  cout << b.size() << endl;
  cout << b[0] << endl;
  cout << b.test(0) << endl;
  cout << b.flip() << endl;
  cout << b.flip(4) << endl;
  cout << b.to_ulong() << endl;
  cout << b.set() << endl;
  cout << b.reset() << endl;
  
  return 0; 
}
