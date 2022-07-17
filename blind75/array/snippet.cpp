#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(const string& s, const string& del){
    size_t pos1, pos2;
    vector<string> vec;
    pos2 = s.find(del);
    pos1 = 0;
    while (pos2 != string::npos){
        vec.push_back(s.substr(pos1, pos2 - pos1));
        pos1 = pos2 + del.size();
        pos2 = s.find(del, pos1);
    }
    if (pos1 != s.size()){
        vec.push_back(s.substr(pos1));
    }
    return vec;
}

void input(std::vector<int>& nums){
    string s;
    cout << "nums = ";
    cin >> s;
    vector<string> svec = split(s, ",");
    for (size_t i = 0; i < svec.size(); i++){
        nums.push_back(stoi(svec[i]));
    }
}

