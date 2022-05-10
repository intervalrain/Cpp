#include <iostream>
#include <vector>
#include "print.cpp"
using namespace std;

template <typename T>
void status(vector<T>& vec){
    print(vec);
    cout << "    The current size: " << vec.size() << endl;
    cout << "The current capacity: " << vec.capacity() << endl;
    cout << "===========================" << endl;
}

int main(){
    vector<int> vec;
    status(vec);

    vec.push_back(1);
    status(vec);

    vec.push_back(2);
    status(vec);

    vec.push_back(3);
    status(vec);

    vec.push_back(4);
    status(vec);

    vec.push_back(5);
    status(vec);

    return 0;
}
