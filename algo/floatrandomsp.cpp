#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));

    double a = 3.14;  // min
    double b = 8.76;  // max

    double x = (b - a) * rand()/(RAND_MAX + 1.0) + a;

    cout << "x = " << x << endl;

    return 0;
}
