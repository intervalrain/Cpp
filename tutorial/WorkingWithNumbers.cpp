#include <iostream>
#include <cmath>

using namespace std;

int main(){

  int wnum = 5;
  double dnum = 12.0;

  // increment and decrement operator
  wnum--;
  wnum++;
  wnum += 80;

  cout << wnum << endl;
  cout << "dnum/wnum = " << dnum / wnum << endl;

  // pow, sqrt, round , floor function in cmath library.
  cout << "pow(3,3) = " << pow(3, 3) << endl;   // 27
  cout << "sqrt(36) = " << sqrt(36) << endl;    // 6
  cout << "round(4.4) = " << round(4.4) << endl;  // 4
  cout << "round(4.6) = " << round(4.6) << endl;  // 5
  cout << "floor(4.6) = " << floor(4.6) << endl;  // 4

  // define integer array.
  int nums[] = {4,1,9,6,2,7};
  int min = INT_MAX, max = INT_MIN;
  for (int i = 0; i < sizeof(nums)/sizeof(int); i++){
      // get maximum or minimum of two integer.
      min = fmin(min, nums[i]);
      max = fmax(max, nums[i]);
  }
  cout << "max = " << max << endl;
  cout << "min = " << min << endl;

  return 0;

}
