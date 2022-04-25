#include <iostream>

int main(){

  int score[5] = {0, 1, 2, 3, 4};
  std::cout << "int score[5] = {0, 1, 2, 3, 4};" << std::endl;
  std::cout << "score: " << score << std::endl;
  std::cout << "score + 2: " << score + 2 << std::endl;
  std::cout << "score[0]: " << score[0] << std::endl;
  std::cout << "score[2]: " << score[2] << std::endl;

  return 0;
}
