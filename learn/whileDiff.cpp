#include <iostream>

int main(){
  const char *cp = "hello";
  int cnt;
  while (cp){
    ++cnt;
    ++cp;
  }


  while (*cp){
    ++cnt;
    ++cp;
  }

  return 0;
}
