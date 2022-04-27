#include <iostream>

using namespace std;

int main(){

    char src[] = "source";
    char dest[100] = "destination";

    strcat(dest, src);   // dest = dest & src

    cout << "dest: " << dest << endl;
    cout << "src: " << src << endl;

    return 0;
}
