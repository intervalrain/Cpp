#include <iostream>

int main(){
    int a = 10;
    int b = 20;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}
