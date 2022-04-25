#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));

    int a = 1;    // min
    int b = 100;  // max

    int x = rand() % (b - a + 1) + a;

    cout << "x = " << x << endl;

    return 0;
}
