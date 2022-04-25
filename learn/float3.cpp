#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
  for (int i = 0; i < 100; i++){
    float f = sqrt(i);
    cout << f << " ";
    cout << setprecision(10);
    cout << f * f << " ";
    cout << endl;
  }
  return 0;
}

