#include <iostream>
#include <vector>
#include "print.cpp"
using namespace std;

//void print(vector<int> vec){
//    for (int i = 0; i < vec.size(); i++){
//        cout << vec[i] << " ";
//    }
//    cout << endl;
//}


int main(){

    // (1) vector<data_type> vector_name;
    // (2) vector<data_type> vector_name(int n);
    // (3) vector<data_type> vector_name(int n, int val);


  vector<int> vec1;
  vec1.push_back(3);

  vector<int> vec2(5);

  vector<int> vec3(3, 1);

  print(vec1);    // 3
  print(vec2);    // 0, 0, 0, 0, 0
  print(vec3);    // 1, 1, 1

}
