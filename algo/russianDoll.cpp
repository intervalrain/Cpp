#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution{
public:
    int maxEnvelopes(vector<vector<int>>& envelopes){
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
        });
        vector<int> dp;
        for (auto& env : envelopes){
            auto iter = lower_bound(dp.begin(), dp.end(), env[1]);
            if (iter == dp.end())
                dp.push_back(env[1]);
            else
                *iter = env[1];
        }
        return dp.size();
    }
};

int main(){
    Solution* sol = new Solution;
    vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3},{1,1}};
    cout << sol->maxEnvelopes(envelopes) << endl;  // 4

    delete sol;
}