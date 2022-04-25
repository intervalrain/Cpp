#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> ivec;
  int cnt = 10;
  while (cnt > 0){
    ivec.push_back(cnt--);
  }
  
  vector<int>::iterator iter;
  
  iter = ivec.begin();
  while (iter != ivec.end())
    cout << *iter++ << " ";
  cout << endl;

  iter = ivec.begin();
  while (iter != ivec.end())
    cout << *++iter << " ";
  cout << endl;

  return 0;
}
