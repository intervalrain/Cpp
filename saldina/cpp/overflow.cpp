#include <iostream>

using namespace std;

int main(){
    int intMax = INT_MAX;
    int intMin = INT_MIN;

    cout << "Maximum integer is " << intMax << endl;
    cout << "Minimum integer is " << intMin << endl;
    cout << "If overflow happened. It turns out ..." << endl;

    cout << "intMax + 1 = " << intMax + 1 << endl;

    return 0;
}
