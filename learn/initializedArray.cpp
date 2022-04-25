#include <iostream>
using namespace std;

int main(){
  int daysInMonth1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int daysInMonth2[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int daysInMonth3[12] = {31, 28, 31};

  for (int i = 0; i < sizeof(daysInMonth1)/sizeof(int); i++){
    cout << daysInMonth1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < sizeof(daysInMonth2)/sizeof(int); i++){
    cout << daysInMonth2[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < sizeof(daysInMonth3)/sizeof(int); i++){
    cout << daysInMonth3[i] << " ";
  }
  return 0;
}
