#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);
        int cnt = rooms.size();
        vector<bool> used(rooms.size(), false);
        while (!q.empty()){
            int key = q.front();
            q.pop();
            if (used[key]) continue;
            cnt--;
            if (cnt == 0) break;
            used[key] = true;
            for (int next : rooms[key]){
                if (used[next]) continue;
                q.push(next);
            }
        }
        return cnt == 0;

    }
};
// @lc code=end

