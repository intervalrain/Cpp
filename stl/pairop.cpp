#include <iostream>
#include <utility>
using namespace std;

int main(){
    pair<int,int> pair1 = make_pair(1, 12);
    pair<int,int> pair2 = make_pair(9, 12);

    cout << (pair1 == pair2) << endl;  // 0
    cout << (pair1 != pair2) << endl;  // 1
    cout << (pair1 >= pair2) << endl;  // 0
    cout << (pair1 <= pair2) << endl;  // 1
    cout << (pair1 > pair2) << endl;   // 0
    cout << (pair1 < pair2) << endl;   // 1

    pair1 = pair2;
    cout << (pair1 == pair2) << endl;  // 1

    return 0;
}
