#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        deque<int> dq;
        for (int i = 0; i < k; i++){
            dq.push_back(arr[i]);
        }
        for (int i = k; i < arr.size(); i++){
            if (abs(dq.front()-x) > abs(arr[i]-x)){
                dq.pop_front();
                dq.push_back(arr[i]);
            } else if (abs(dq.front()-x) < abs(arr[i]-x)){
                break;
            }
        }
        return vector<int> (dq.begin(), dq.end());
    }
};
// @lc code=end

