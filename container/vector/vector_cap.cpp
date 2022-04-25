#include <bits/stdc++.h>

#include "print.cc"

using namespace std;

int main(){
    vector<int> vec;
    for (int i = 0; i <= 12; ++i)
        vec.push_back(i);
    cout << "Max_size: " << vec.max_size() << "\n";

    cout << "==================================\n";
    cout << "Initial" << "\n";
    cout << "Size: " << vec.size() << "\n";
    cout << "Capacity: " << vec.capacity() << "\n";
    print(vec);
    cout << "==================================\n";

    vec.resize(8);
    cout << "After resize(8)" << "\n";
    cout << "Size: " << vec.size() << "\n";
    cout << "Capacity: " << vec.capacity() << "\n";
    print(vec);
    cout << "==================================\n";

    vec.shrink_to_fit();
    cout << "After fitting" << "\n";
    cout << "Size: " << vec.size() << "\n";
    cout << "Capacity: " << vec.capacity() << "\n";
    print(vec);
    cout << "==================================\n";

    vec.reserve(20);
    cout << "After reserve(20)" << "\n";
    cout << "Size: " << vec.size() << "\n";
    cout << "Capacity: " << vec.capacity() << "\n";
    print(vec);
    cout << "==================================\n";

    cout << "If the vector is empty: ";
    vec.empty() ? (cout << "Empty") : (cout << "Not empty") << "\n";

    return 0;
}