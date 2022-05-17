#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string trans(string s){
        int n = s.length();
        string res;
        for (int i = 0; i < n; ++i){
            if (s[i] == '#')
                res.pop_back();
            else
                res.push_back(s[i]);
        }
        return res;
    }

    bool backspaceCompare(string s, string t){
        return trans(s) == trans(t);
    }
};

int main(){
    Solution* sol;
    string s, t;

    cin >> s >> t;

    cout << (sol->backspaceCompare(s, t) ? "the same" : "different") << endl;

    return 0;
}
