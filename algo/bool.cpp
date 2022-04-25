#include <iostream>

void utility(bool a){
    std::cout << std::boolalpha << a << std::endl;
}

int main(){
    utility(true);
    utility(false);

    return 0;
}