#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> vec1 {1,3,7,9,11,17,23};
    all_of(vec1.begin(), vec1.end(), [](int x) { return (x & 1) == 1;}) ? cout << "All odds\n" : cout << "Not all odds\n";

    vector<int> vec2 {1,3,6,8,9,11,13};
    any_of(vec2.begin(), vec2.end(), [](int x) { return (x & 1) == 0;}) ? cout << "There are at least one even\n" : cout << "There are no any even\n";

    none_of(vec1.begin(), vec1.end(), [](int x) { return (x & 1) == 0;}) ? cout << "There are no any even\n" : cout << "There are at least one even\n";

    return 0;
}