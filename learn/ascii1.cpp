#include <iostream>
using namespace std;

int main(){
  for (int c = 33; c <= 126; c++){
    cout << c << ": ";
    char cAsChar = c;
    cout << cAsChar << endl;
  }
  return 0;
}
