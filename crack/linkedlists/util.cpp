#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "listnode.cpp"

using namespace std;

vector<string> split(string s, string del){
    int i = 0;
    int k = del.length();
    vector<string> res;
    while (i + k < s.length()){
        if (s.substr(i, k) == del){
            string tmp = s.substr(0, i);
            res.push_back(tmp);
            s = s.substr(i+k);
            i = 0;
        } else {
          i++;
        }
    }
    res.push_back(s);
    return res;
}

vector<int> getNums(){
    string s;
    cout << "Please input an array: ";
    getline(cin, s);

    if (s[0] == 'q' || s[0] == 'Q') exit(0);

    vector<string> svec = split(s, ",");
    vector<int> ivec;
    for (int i = 0; i < svec.size(); i++){
        ivec.push_back(stoi(svec[i], nullptr, 10));
    }

    return ivec;
}

