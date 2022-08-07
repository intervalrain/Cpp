#include <iostream>

using namespace std;

class Solution{
  public:
    bool canFinish(int n, vector<vector<int>>& pre){
        vector<vector<int>> graph(n, vector<int>());
        vector<int> limit(n, 0);
        queue<int> q;
        for (auto& p : pre){
            graph[p[1]].push_back(p[0]);
            limit[p[0]]++;
        }
        for (int i = 0; i < n; i++){
            if (limit[i] == 0) q.push(i);
        }
        while (!q.empty()){
            int x = q.front();
            q.pop();
            n--;
            for (int& g: graph[x]){
                limit[g]--;
                if (limit[g] == 0) q.push(g);
            }
        }
        return n == 0;
    }

    vector<int> findOrder(int n, vector<vector<int>>& pre){
        vector<vector<int>> graph(n, vector<int>());
        vector<int> limit(n, 0);
        queue<int> q;
        vector<int> res;
        for (auto& p : pre){
            graph[p[1]].push_back(p[0]);
            limit[p[0]]++;
        }
        for (int i = 0; i < n; i++){
            if (limit[i] == 0) q.push(i);
        }
        while (!q.empty()){
            int x = q.front();
            q.pop();
            res.push_back(x);
            n--;
            for (int& g: graph[x]){
                limit[g]--;
                if (limit[g] == 0) q.push(g);
            }
        }
        return n == 0 ? res : vector<int>();
    }
};
