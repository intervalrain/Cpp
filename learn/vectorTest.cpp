#include <iostream>
#include <vector>

using std::vector;
using namespace std;

int main(){
  vector<int> vec1;
  vector<int> vec2(vec1);
  vector<int> vec3 = {1, 2, 3, 4, 5, 6, 7};
  vector<int> vec4(vec3.begin()+2, vec3.end()-1);
  vector<int> vec5(7);
  vector<int> vec6(7, 0);
  
  for (vector<int>::size_type idx = 0; idx < vec4.size(); ++idx){
    cout << vec4[idx] << " ";
  }


  return 0;
}
