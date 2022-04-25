#include <iostream>
#include <vector>

using std::vector;
using namespace std;

int main(){
  vector<int> ivec = {0, 0, 2, 1, 3, 5, 1, 0, 6, 7, 3, 2, 5, 2};

  for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter){
    cout << *iter << " ";
  }
  
  return 0;
}
