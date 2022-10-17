#include <bits/stdc++.h>
using namespace std;

vector<string> split(string& str, char del){
    stringstream ss(str);
    string item;
    vector<string> res;
    while (getline(ss, item, del)){
        if (!item.empty()){
            res.push_back(item);
        }
    }
    return res;
}

string concat(vector<string>& svec, char del){
    stringstream ss;
    for (const auto& s : svec){
        ss << s << del;
    }
    return ss.str();
}

int main(){
    string s = "is2 sentence4 This1 a3";
    vector<string> svec = split(s, ' ');
    string res = concat(svec, ' ');
    cout << res << endl;

    return 0;
}
