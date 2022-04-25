#include <iostream>

int main(){
  const char *pc = "A test string";
  const size_t len = strlen(pc + 1);
  for (size_t ix = 0; ix != len; ++ix){
    char *pc2 = new char[len + 1];
    strcpy(pc2, pc);
    std::cout << *pc2;
    delete [] pc2;
    pc++;
 }
  return 0;
}
