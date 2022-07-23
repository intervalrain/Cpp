#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

string plus1(string s, int j){
    s[j] = s[j] == '9' ? '0' : s[j] + 1;
    return s;
}

string minus1(string s, int j){
    s[j] = s[j] == '0' ? '9' : s[j] - 1;
    return s;
}

int steps(string[] deadends, string target){
    unordered_set<string> deads;
    for (string s : deadends) deads.insert(s);
    unordered_set<string> visited;
    queue<string> q;

    int step = 0;
    q.push("0000");
    visited.insert("0000");

    while (!q.empty()){
        int n = q.size();
        for (int i = 0; i < n; i++){
            string curr = q.front();
            q.pop();
            if (deads.count(curr)){
                continue;
            }
            if (curr == target){
                return step;
            }
            for (int j = 0; j < target.length(); j++){
                string up = plus1(curr, j);
                if (!visited.count(up)){
                    q.push(up);
                    visited.insert(up);
                }
                string down = minus1(curr, j);
                if (!visited.count(down)){
                    q.push(down);
                    visited.insert(down);
                }
            }
        }
        step++;
    }
    return -1;
}

int steps2(string[] deadends, string target){
    unordered_set<string> deads;
    for (string s : deadends) deads.insert(s);
    unordered_set<string> visited;
    unordered_set<string> q1;
    unordered_set<string> q2;

    int step = 0;
    q1.insert("0000");
    q2.insert(target);

    while (!q1.empty() && !q2.empty()){
        if (q1.size() > q2.size()){
            auto temp = q1;
            q1 = q2;
            q2 = temp;
        }
        unordered_set<string> temp;
        for (string curr : q1){
            if (deads.count(curr))
                continue;
            if (q2.count(curr))
                return step;
            visited.insert(curr);

            for (int j = 0; j < target.length(); j++){
                string up = plus1(curr, j);
                if (!visited.count(up))
                    temp.insert(up);
                string down = minus1(curr, j);
                if (!visted.count(down))
                    temp.insert(down);
            }
        }
        step++;
        q1 = q2;
        q2 = temp;
    }
    return -1;
}