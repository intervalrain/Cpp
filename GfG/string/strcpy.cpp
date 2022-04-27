#include <iostream>

using namespace std;

int main(){
    char dest[100];
    char src[] = "Hello World!";
    strcpy(dest, src);    // dest copy from src

    cout << "destination: " << dest << endl;
    cout << "source: " << src << endl;

    return 0;

}
