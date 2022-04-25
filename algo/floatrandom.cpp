#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));
    double x = (double)rand()/(RAND_MAX + 1.0);

    cout << "x = " << x << endl;

    return 0;
}
