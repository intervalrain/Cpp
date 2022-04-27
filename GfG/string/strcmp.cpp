#include <iostream>

using namespace std;

int main(){
    char str1[] = "abc";
    char str2[] = "abcd";
    char str3[] = "abb";

    // lexicographical order: str3 > str2 > str1
    cout << strcmp(str1, str2) << endl;   // -100
    cout << strcmp(str1, str3) << endl;   // 1
    cout << strcmp(str2, str3) << endl;   // 1

    return 0;
}
