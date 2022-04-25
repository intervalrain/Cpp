#include <iostream>
using namespace std;

void reversePrint(int);
int main(){
  int i = 0;
  cin >> i;
  reversePrint(i);
  return 0;
}

void reversePrint(int i){
  if (i < 0)
    return;
  while (i > 0){
    cout << i % 10;
    i /= 10;
  }
  cout << endl;
  return;
}
