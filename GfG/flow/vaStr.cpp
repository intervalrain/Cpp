#include <bits/stdc++.h>
using namespace std;

void printLine(char* first, ...){
    char* str;
    va_list ap;

    str = first;
    va_start(ap, first);
    do {
        cout << str << "\n";
        str = va_arg(ap, char*);
    } while (str != NULL);
    va_end(ap);
}

int main(){
    printLine("first", "second", "third", "fourth", "fifth");
    system("pause");
    return 0;
}
