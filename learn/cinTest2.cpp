#include <iostream>

using namespace std;
using std::string;

int main(){
  string line;
  while (getline(cin, line, ' ')){
    cout << line << endl;
  cout << line.size() << endl;
  return 0;
  } 
}
