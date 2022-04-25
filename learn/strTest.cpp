#include <iostream>

using std::string;
using namespace std;

int main(){
  string str("some string");
  for (string::size_type ix = 0; ix != str.size(); ++ix){
    cout << str[ix] <<endl;
  }
  return 0;
}
