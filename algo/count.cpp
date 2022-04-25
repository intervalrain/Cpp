// C++ program to demonstrate working of count()
// and find()
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int arr[] = {10, 20, 5, 23 ,42, 20, 15};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> vec(arr, arr + n);
	cout << count(vec.begin(), vec.end(), 20);      // 2

	find(vec.begin(), vec.end(),5) != vec.end() ? 
					   cout << "\nElement found":
				   cout << "\nElement not found";

	return 0;
}

