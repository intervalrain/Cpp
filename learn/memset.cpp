#include <iostream>
#include <string>

using namespace std;

int main(){
    char ch[10];
    memset(ch, 'a', 5 * sizeof(char));
    memset(ch+5, 'b', 5 * sizeof(char));

    for (int i = 0; i < 10; i++){
        cout << ch[i];
    }
    cout << endl;

    return 0;
}
