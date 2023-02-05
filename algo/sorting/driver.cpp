#include <iostream>
#include <sstream>
#include <string>
#include "timSort.cpp"

using namespace std;

vector<string> split(string& str, char del) {
    stringstream ss(str);
    string item;
    vector<string> res;
    while (getline(ss, item, del)) {
        if (!item.empty()) {
            res.push_back(item);
        }
    }
    return res;
}

void print(vector<int>& nums) {
    for (const auto& num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    string str;
    cout << "Please input an array: ";
    getline(cin, str);
    auto svec = split(str, ' ');
    int n = svec.size();
    vector<int> nums;
    for (const auto& s : svec) {
        nums.push_back(stoi(s));
    }
    sort(nums);
    print(nums);

    return 0;
}
