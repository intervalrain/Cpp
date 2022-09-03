#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=492 lang=cpp
 *
 * [492] Construct the Rectangle
 */

// @lc code=start
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int sq = sqrt(area);
        
        for (int i = sq; i <= area; i++){
            int div = area/i;
            if (div * i == area && div <= i) return {i, div};
        }
        return {area, 1};
    }
};
// @lc code=end

