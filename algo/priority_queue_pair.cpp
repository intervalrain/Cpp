#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class comp{
  public:
    bool operator()(const pair<char,int>& a, const pair<char,int>& b){
        return a.second < b.second;
    }
};

class Solution{
  public:
    void taskInterval(vector<char>& tasks){
        unordered_map<char,int> map;
        for (int i = 0; i < tasks.size(); i++){
            map[tasks[i]]++;
        }
        priority_queue<pair<char,int>, vector<pair<char,int>>, comp> pq(map.begin(), map.end());

        while (!pq.empty()){
            cout << pq.top().first << pq.top().second << endl;
            pq.pop();
        }
    }
};

int main(){
    vector<char> tasks = {'A', 'A', 'A', 'A', 'B', 'B', 'C', 'D', 'D', 'D', 'D', 'D'};
    Solution* sol = new Solution();
    sol->taskInterval(tasks);

    return 0;
}
