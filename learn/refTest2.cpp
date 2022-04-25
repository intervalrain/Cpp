#include <iostream>

using namespace std;

int main(){
  int ival1 = 1024;
  int ival2 = 2048;

  int *pi1 = &ival1;
  int *pi2 = &ival2;

  pi1 = pi2;

  cout << "ival1: " << ival1 << endl;
  cout << "ival2: " << ival2 << endl;
 
  int &ri1 = ival1;
  int &ri2 = ival2;

  ri1 = ri2;

  cout << "ival1: " << ival1 << endl;
  cout << "ival2: " << ival2 << endl; 

  return 0;
}
