#include <iostream>
#include <cmath>
using namespace std;

/* imprecise comparison */

int main(){

  for (int i = 0; i < 100; i++){
    float f = sqrt(i);
    cout << f << " ";
    cout << f * f;
    if (abs(f * f - i) > 0.0001){
      cout << "!!!";
    }
    cout << endl;
  }
  return 0;
}
