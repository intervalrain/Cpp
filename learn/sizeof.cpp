#include <iostream>

using namespace std;

int main(){
  cout << "int: " << sizeof(int) << endl;
  cout << "char: " << sizeof(char) << endl;
  cout << "bool: " << sizeof(bool) << endl;
  short s = 0;
  cout << "short int: " << sizeof(s) << endl;
  long l = 0;
  cout << "long int: " << sizeof(l) << endl;

  cout << "unsigned short int: " << sizeof(unsigned short) << endl;
  cout << "unsinged int: " << sizeof(unsigned) << endl;
  cout << "unsigned long int: " << sizeof(unsigned long) << endl;
  
  return 0;
}
