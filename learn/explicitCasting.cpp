#include <iostream>
using namespace std;

int main(){

  /* bad one: there's 4 possibilities to do casting:
   * (1) static_cast
   * (2) dynamic_cast
   * (3) reindivter_cast
   * (4) const_cast
   */  

  int b = (int) 6.5;
  cout << b << endl;  

  // good one
  int a = static_cast<int>(5.6);
  cout << a << endl;

  return 0;
}
