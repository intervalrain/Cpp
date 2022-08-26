#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 */

// @lc code=start
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (startFuel >= target) return 0;
        if (startFuel < target && stations.size() == 0);
        priority_queue<int> pq;
        pq.push(startFuel);
        int cnt = 0;
        int reach = 0;
        int i = 0;
        while (!pq.empty()){
            reach += pq.top();
            pq.pop();
            if (reach >= target) return cnt;
            for (; i < stations.size(); i++){
                if (reach < stations[i][0]) break;
                pq.push(stations[i][1]);
            }
            cnt++;

        }
        return -1;
    }
};
// @lc code=end

