/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        if (dungeon[m-1][n-1] > 0) dungeon[m-1][n-1] = 0;
        for (int j = n-2; j >= 0; j--){
            dungeon[m-1][j] += dungeon[m-1][j+1];
            if (dungeon[m-1][j] > 0) dungeon[m-1][j] = 0;
        }
        for (int i = m-2; i >= 0; i--){
            dungeon[i][n-1] += dungeon[i+1][n-1];
            if (dungeon[i][n-1] > 0) dungeon[i][n-1] = 0;
            for (int j = n-2; j >= 0; j--){
                dungeon[i][j] += max(dungeon[i+1][j], dungeon[i][j+1]);
                if (dungeon[i][j] > 0) dungeon[i][j] = 0;
            }
        }
        return dungeon[0][0] > 0 ? 1 : 1-dungeon[0][0];
    }
};
// @lc code=end

