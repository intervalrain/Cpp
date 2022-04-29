#include <bits/stdc++.h>
using namespace std;

int main(){
    char s1[] = "GeeksforGeeks";
    char s2[] = "for";
    char *p;

    // just like indexOf in Java.   strstr(toal_str, to_find), return a pointer.
    p = strstr(s1, s2);

    // if p exists, print chars until '\0'
    if (p)
        cout << "First occurence of string: '" << s2 << "'\n in '" << s1 << "' is '" << p << "'" << endl;
    else
        cout << "String not found.\n";

    return 0;
}
