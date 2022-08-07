#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {

//mm by mb by mb mb bb by my mb 42
//["mm","mm","yb","by","bb","bm","ym","mb","yb","by","mb","mb","bb","yb","by","bb","yb","my","mb","ym"]
    //"mm","mm"
    //"yb","by"
    //"yb","by"
    //"yb","by"
    //"bb","bb","bb"
    //"bm","mb"
    //"ym","my"
    //"mb","mb","yb","mb","ym"]
public:
    int longestPalindrome(vector<string>& words) {
        int pair = 0;
        unordered_map<int, int> pmap;
        unordered_map<int, int> dmap;
        for (string word : words){
            if (word[0] == word[1]){
                int num = encode(word);
                if (dmap.count(num)){
                    pair += 2;
                    cout << word << "(pair) ";
                    dmap[num]--;
                    if (dmap[num] == 0) dmap.erase(dmap.find(num));
                } else {
                    dmap[num]++;
                    cout << word << "(sing) ";
                }
            } else {
                int num = encode(word);
                if (pmap.count(-num)){
                    pair += 2;
                    cout << word << "(pair) ";
                    pmap[-num]--;
                } else {
                    pmap[num]++;
                    cout << word << "(sing) ";
                }
            }
        }
        return dmap.size() > 0 ? (pair+1)*2 : pair*2;
    }
    int encode(string s){
        int num = 0;
        for (int i = 0; i < s.length(); i++){
            num |= (1 << (s[i]-'a'));
        }
        if (s[0] == s[1]) return num;
        return s[0] > s[1] ? -num : num;
    }
};

int main(){
    Solution* sol = new Solution();
    vector<string> words = {"mm","mm","yb","by","bb","bm","ym","mb","yb","by","mb","mb","bb","yb","by","bb","yb","my","mb","ym"};
    int res = sol->longestPalindrome(words);
    cout << res << endl;

    return 0;
}
