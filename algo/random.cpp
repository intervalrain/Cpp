#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));
    int x = rand();

    cout << "x = " << x << endl;
    cout << "x is between 0 and " << RAND_MAX << endl;

    return 0;
}
