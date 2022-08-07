#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution{
  public:
    string alienOrder(vector<string>& words){
        vector<int> indegree(26, 0);
        unordered_map<char, unordered_set<char>> g;
        buildGraph(g, words, indegree);
        return bfs(g, indegree);
    }

    void buildGraph(unordered_map<char, unordered_set<char>>& g, vector<string>& words, vector<int>& indegree){
        for (string word : words){
            for (char c : word){
                if (!g.count(c)){
                    g[c] = unordered_set<char>();
                }
            }
        }

        for (int i = 1; i < words.size(); i++){
            string first = words[i-1];
            string second = words[i];
            int len = min(first.length(), second.length());
            for (int j = 0; j < len; j++){
                if (first[j] != second[j]){
                    char prev = first[j];
                    char next = second[j];
                    if (!g[prev].count(next)){
                        g[prev].insert(next);
                        indegree[next -'a']++;
                    }
                    break;
                }
            }
        }
    }
// t->f
// w->e
// r->t    w->e->r->t->f
// e->r
//
// [t,w,r,e,f] = [1,0,1,1,1]
//
    string bfs(unordered_map<char, unordered_set<char>>& g, vector<int>& indegree){
        string s;
        int totalLength = g.size();
        queue<char> q;
        for (auto cs : g){
            char c = cs.first;
            if (indegree[c - 'a'] == 0){
                s.push_back(c);
                q.push(c);
            }
        }

        while (!q.empty()){
            char out = q.front();
            q.pop();
            if (g[out].size() == 0){
                continue;
            }
            for (char in : g[out]){
                indegree[in - 'a']--;
                if (indegree[in - 'a'] == 0){
                    q.push(in);
                    s.push_back(in);
                }
            }
        }

        return s.length() == totalLength ? s : "";

    }
};

int main(){
    vector<string> s = {{"wrt"},
                        {"wrf"},
                        {"er"},
                        {"ett"},
                        {"rftt"}};
    Solution* sol = new Solution();
    string res = sol->alienOrder(s);

    cout << res << endl;

    return 0;
}
