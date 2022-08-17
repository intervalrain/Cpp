/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
class Solution {
public:
    // single bfs
    // int openLock(vector<string>& deadends, string target) {
    //     unordered_set<string> deads(deadends.begin(), deadends.end());
    //     set<string> visited;
    //     queue<string> q;
    //     int step = 0;
    //     string start = "0000";
    //     q.push(start);
    //     visited.insert(start);
    //     while (!q.empty()){
    //         int sz = q.size();
    //         for (int i = 0; i < sz; i++){
    //             string curr = q.front();
    //             q.pop();
    //             if (deads.count(curr)) continue;
    //             if (curr == target) return step;

    //             for (int i = 0; i < 4; i++){
    //                 string up = plusOne(curr, i);
    //                 string down = minusOne(curr, i);
    //                 if (!visited.count(up)){
    //                     q.push(up);
    //                     visited.insert(up);
    //                 }
    //                 if (!visited.count(down)){
    //                     q.push(down);
    //                     visited.insert(down);
    //                 }
    //             }
    //         }
    //         step++;
    //     }
    //     return -1;
    // }

    // double bfs
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end());
        unordered_set<string> q1;
        unordered_set<string> q2;
        set<string> visited;

        int step = 0;
        string start = "0000";
        q1.insert(start);
        q2.insert(target);
        
        while (!q1.empty() && !q2.empty()){
            unordered_set<string> tmp;
            for (string curr : q1){
                if (deads.count(curr)) continue;
                if (q2.count(curr)) return step;

                visited.insert(curr);

                for (int i = 0; i < 4; i++){
                    string up = plusOne(curr, i);
                    string down = minusOne(curr, i);
                    if (!visited.count(up)){
                        tmp.insert(up);
                    }
                    if (!visited.count(down)){
                        tmp.insert(down);
                    }
                }
            }
            step++;
            if (q1.size() > q2.size()){
                q1 = tmp;
            } else {
                q1 = q2;
                q2 = tmp;
            }
        }
        return -1;
    }
    string plusOne(string s, int i){
        s[i] = s[i] == '9' ? '0' : (s[i] + 1);
        return s;
    }
    string minusOne(string s, int i){
        s[i] = s[i] == '0' ? '9' : (s[i] - 1);
        return s;
    }
};
// @lc code=end

