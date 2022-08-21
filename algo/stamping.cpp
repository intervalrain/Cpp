#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        int m = stamp.length(), n = target.length();
        if (stamp.length() == target.length() && stamp != target) return res;
        if (stamp.length()*10 < target.length()) return res;
        bool visited[n];
        memset(visited, false, sizeof(visited));

        int left = target.length();
        while (left > 0){
            bool flag = false;

            for (int i = 0; i <= target.length()-stamp.length(); i++){
                if (!visited[i] && isValid(target, stamp, i)){
                    left -= paint(target, m, i);
                    flag = true;
                    visited[i] = true;
                    res.push_back(i);
                    if (left == 0) break;
                }
            }

            if (!flag){
                return {};
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
    bool isValid(string& target, string& stamp, int start){
        for (int i = 0; i < stamp.length(); i++){
            if (target[start+i] == '#') continue;
            if (target[start+i] != stamp[i]) return false;
        }
        return true;
    }
    int paint(string& target, int n, int start){
        int cnt = 0;
        for (int i = start; i < start + n; i++){
            if (target[i] == '#') continue;
            target[i] = '#';
            cnt++;
        }
        return cnt;
    }
};

int main(){
    Solution* sol = new Solution();
    string stamp = "abca";
    string target = "aabcaca";
    vector<int> res = sol->movesToStamp(stamp, target);
    for_each(res.begin(), res.end(), [](int x){cout << x << " ";});

    return 0;
}
