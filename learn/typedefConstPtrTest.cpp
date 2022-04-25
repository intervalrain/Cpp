#include <iostream>

using namespace std;

int main(){
  string s("hello world!");
  typedef string *pstring;

  const pstring cstr1 = &s;
  pstring const cstr2 = &s;
  string *const cstr3 = &s;
  string const *cstr4 = &s;

  cout << *cstr1 << endl;
  cout << *cstr2 << endl;
  cout << *cstr3 << endl;
  cout << *cstr4 << endl;

  return 0;
}

