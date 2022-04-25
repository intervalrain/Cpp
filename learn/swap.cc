#include <iostream>

/**
 * pointer
 */
void c_swap(int* pa, int* pb){
    int tmp;
    tmp = (*pa);
    (*pa) = (*pb);
    (*pb) = tmp;
}

/**
 * reference
 */
void cpp_swap(int& a, int& b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main(){
    int a = 3;
    int b = 5;
    std::cout << "a = " << a << " ; b = " << b << std::endl;
    c_swap(&a, &b);
    std::cout << "a = " << a << " ; b = " << b << std::endl;
    cpp_swap(a, b);
    std::cout << "a = " << a << " ; b = " << b << std::endl;
    
    return EXIT_SUCCESS;
}