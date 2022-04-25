#include <iostream>
#include <cstring>

int main(){

  const char *cp1 = "A string example";
  const char *cp2 = "A different string.";
  char str[34];
  strcpy(str, cp1);
  strcat(str, " ");
  strcat(str, cp2);

  std::cout << str << std::endl;

  return 0;
}
