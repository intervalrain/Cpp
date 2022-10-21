/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
class SegTree {
    vector<int> arr;
    int m, n;
public:
    SegTree(int sz) {
        n = sz;
        for (m=1; m < n; m <<= 1);
        arr.assign(2*m, 0);
    }
    void update(int left, int right, int val) {
        int i = left+m, j = right+m;
        for(; i <= j; i >>= 1, j >>= 1) {
            if (i & 1) arr[i++] = max(arr[i], val);
            if (~j & 1) arr[j--] = max(arr[j], val);
        }
    }
    void pushdown() {
        for (int i = 1; i < m; i++) {
            arr[i<<1] = max(arr[i<<1], arr[i]);
            arr[i<<1|1] = max(arr[i<<1|1], arr[i]);
        }
    }
    int query(int i) {
        return arr[i+m];
    }
};
class Solution {
    unordered_map<int,int> x2i, i2x;
public:
    int mapping(vector<vector<int>>& buildings) {
        set<int> sets;
        for (const auto& b : buildings) {
            sets.insert(b[0]);
            sets.insert(b[1]);
        }
        int cnt = 0;
        for (const auto& x : sets) {
            i2x[cnt] = x;
            x2i[x] = cnt++;
        }
        return cnt;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = mapping(buildings);
        SegTree* root = new SegTree(n);
        for (const auto& b : buildings) {
            int s = x2i[b[0]];
            int e = x2i[b[1]];
            root->update(s, e-1, b[2]);
        }
        root->pushdown();

        vector<vector<int>> res;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            int x = i2x[i];
            int y = root->query(i);
            if (prev != y) {
                res.push_back({x, y});
                prev = y;
            }
        }
        return res;
    }
};
// @lc code=end

