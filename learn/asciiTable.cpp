#include <iostream>
using namespace std;

int main(){
  cout << "   0 1 2 3 4 5 6 7 8 9\n";
  cout << " 3      ";
  for (int c = 33; c <= 126; c++){
    if (c % 10 == 0){
      if (c / 10 <= 9){
        cout << " ";
      }
      cout << c / 10;
    }
    char cAsChar = c;
    cout << " " << cAsChar;
    if (c % 10 == 9)
      cout << endl;
  }
  return 0;
}
