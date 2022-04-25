#include <iostream>
#include <climits>
using namespace std;

int main(){
  
  double value[10] = {0};
  double max = INT_MIN;
  for (int i = 0; i < 10; i++){
    cin >> value[i];
    max = value[i] > max ? value[i] : max;
  }

  cout << "The max inputs: " << max << endl;

  return 0;
}
