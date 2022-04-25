#include <iostream>
using namespace std;

int main(){
  int score[5];
  for (int i = 0; i < 5; i++){
    cin >> score[i];
  }
  int total;
  for (int i = 0; i < 5; i++){
    total += score[i];
  }
  cout << "total is: " << total << endl;
  cout << "*(score+3): " << *(score + 3) << endl;
  cout << "size of int: " << sizeof(int) << endl;
  cout << "size of score: " << sizeof(score) << endl;

  return 0;
}
