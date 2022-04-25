#include <iostream>
using namespace std;

int main(){
    int cnt = 0;

    cnt++;
    cout << cnt << endl;
    cnt--;
    cout << cnt << endl;

    cout << ++cnt << endl;
    cout << cnt-- << endl;
    cout << cnt << endl;

    system("ls");
    return 0;
}
