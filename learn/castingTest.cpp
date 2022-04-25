#include <iostream>
using namespace std;

int main(){
  int grade1 = 0;
  int grade2 = 0;
  
  cin >> grade1 >> grade2;

  cout << static_cast<float>(grade1 + grade2) / 2 << endl;
  cout << static_cast<float>((grade1 + grade2) / 2) << endl;

  return 0;
}
