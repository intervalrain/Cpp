#include <iostream>
#include <bitset>
#include <vector>

using namespace std;
using std::bitset;
using std::vector;

int main(){
  vector<int> ivec(7);
  bitset<32> bvec;
  ivec[0] = 1;
  ivec[1] = 1;
  bvec.flip(ivec[1]);
  for (int idx = 2; idx != 8; ++idx){
    ivec[idx] = ivec[idx-1] + ivec[idx-2];  
    bvec.flip(ivec[idx]);
  }

  cout << bvec << endl; 

  return 0;
}
