#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    bool wordBreak(string s, vector<string>& wordDict){
        vector<bool> used(s.length());
        return helper(s, wordDict, used);
    }
    bool helper(string s, vector<string>& wordDict, vector<bool>& used){
        if (s.length() == 0) return true;
        if (used[s.length()]) return false;
        for (int i = 0; i < wordDict.size(); i++){
            string d = wordDict[i];
            if (isPrefix(s, d)){
                string next = s.substr(d.length(), s.length());
                bool res = helper(next, wordDict, used);
                if (res) return true;
                used[next.length()] = true;
            }
        }
        return false;
    }
    bool isPrefix(string s, string d){
        if (s.length() < d.length()) return false;
        return s.substr(0, d.length()) == d;
    }
};

int main(){
    Solution* sol = new Solution();
    cout << "Please type in the string: ";
    string s;
    cin >> s;
    cout << "Please type in how many words in dict: ";
    int n;
    cin >> n;
    cout << "please type in the words in dict: ";
    vector<string> wordDict(n);
    for (int i = 0; i < n; i++){
        cin >> wordDict[i];
    }

    cout << (sol->wordBreak(s, wordDict) ? "True" : "False") << endl;

    return 0;
}
