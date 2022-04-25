
#include <iostream>
#include <iomanip>

using namespace std;

void precise(int n){
    cout << setprecision(n) << std::fixed;
}

void boolean(){
    std::cout << std::boolalpha;
}

int main(){
    double a = 5.43/2.653;
    bool b = true;

    std::cout << a << std::endl;        // 2.04674
    std::cout << b << std::endl;        // 1

    precise(3);
    boolean();

    std::cout << a << std::endl;        // 2.047
    std::cout << b << std::endl;        // true

    return 0;
}