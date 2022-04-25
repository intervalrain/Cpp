#include <iostream>
using namespace std;

int main(){
  int a[4];
  int b[4];

  for (int i = 0; i < 4; i++)
    cin >> a[i];
  for (int i = 0; i < 4; i++)
    cin >> b[i];
  int total = 0;
  for (int i = 0; i < 4; i++)
    total += a[i]*b[i];

  cout << total << endl;

  return 0;
}
