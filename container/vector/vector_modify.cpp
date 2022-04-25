#include <bits/stdc++.h>
#include "print.cc"

using namespace std;

int main(){
	vector<int> vec;

    cout << "After assign(5, 10): \n";
	vec.assign(5, 10);
    print(vec);

    cout << "After push_back(15): \n";
	vec.push_back(15);
    print(vec);
	int n = vec.size();
	cout << "The last element is: " << vec.back() << "\n";

    cout << "After pop_back(): \n";
	vec.pop_back();
    print(vec);

    cout << "After insert(vec.begin(), 5): \n";
	vec.insert(vec.begin(), 5);
    print(vec);

    cout << "After erase(vec.begin()): \n";
	vec.erase(vec.begin());
    print(vec);

	auto iter = vec.emplace(vec.begin() + 2, 100)
	auto iter = vec.emplace(iter + 2, 200)
	auto iter = vec.emplace(iter + 2, 300)

	vec.clear();
	cout << "Vector size after clear(): " << vec.size() << "\n";

	vector<int> v1, v2;
	v1.push_back(1);
	v1.push_back(2);
	v2.push_back(3);
	v2.push_back(4);

	cout << "Vector 1: ";
	print(v1);

	cout << "Vector 2: ";
	print(v2);

	// Swaps v1 and v2
	v1.swap(v2);

	cout << "After Swap \nVector 1: ";
	print(v1);

	cout << "Vector 2: ";
	print(v2);

    return 0;
}
