#include <bits/stdc++.h>
using namespace std;

class Server{
private:
    int threshold;
    unordered_map<int,int> map;// {id, timetick}
    void enter(vector<int> logFile){
        check(logFile);
        map[logFile[0]] = logFile[1];
    }
    void exit(vector<int> logFile){
        check(logFile);
        auto it = map.find(logFile[0]);
        if (it != map.end()){
            map.erase(it);
        }
    }
    void check(vector<int> logFile){
        int curr = logFile[1];
        queue<int> q;
        for (const auto& m : map){
            if (curr - m.second >= threshold){
                cout << "ID. " << m.first << " is time-out.\n";
                q.push(m.first);
            }
        }
        while (!q.empty()){
            map.erase(q.front());
            q.pop();
        }
    }
public:
    Server(int threshold){
        this->threshold = threshold;
    }
    void read(vector<vector<int>> logFiles){
        for (const auto& logFile : logFiles){
            if (logFile[2] == 0){
                enter(logFile);
            } else if (logFile[2] == 1){
                exit(logFile);
            }
        }
    }
};

int main(){
    vector<vector<int>> logFiles = {
        {1, 1, 0},  // {id, timetick, action}, 0 for enter, 1 for exit.
        {2, 2, 0},
        {1, 3, 1},
        {3, 6, 0},
        {2, 7, 1},
        {3, 8, 1},
        {4,10, 0},
        {5,11, 0},
        {6,11, 0},
        {5,13, 1},
        {6,17, 1}
    };

    int threshold = 3;
    Server server(threshold);
    server.read(logFiles);

    return 0;
}
