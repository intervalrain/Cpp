/*
 * @lc app=leetcode id=1338 lang=cpp
 *
 * [1338] Reduce Array Size to The Half
 */

// @lc code=start
class comp{
public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;  // max-heap
    }
};

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> map;
        for (int x : arr) map[x]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq(map.begin(), map.end());
        int n = arr.size()/2;
        int cnt = 0;
        while (n > 0){
            int sz = pq.top().second;
            pq.pop();
            n -= sz;
            cnt++;
        }
        return cnt;
        
    }
};
// @lc code=end

