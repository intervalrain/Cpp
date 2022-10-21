/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
class SegTree {
    int m, n;
    vector<int> arr;
    int query(int left, int right) {
        int sum = 0;
        int i = left+m, j = right+m;
        for(; i <= j; i >>= 1, j >>= 1) {
            if (i & 1) sum += (arr[i++]);
            if (~j & 1) sum += (arr[j--]);
        }
        return sum;
    }
public:
    SegTree(int sz) {
        n = sz;
        for (m=1; m < n; m <<= 1);
        arr.assign(2*m, 0);
    }
    int count(int idx) {
        return query(idx+1, n-1);
    }
    void add(int idx) {
        idx += m;
        arr[idx] += 1;
        idx >>= 1;
        for (; idx; idx >>= 1) {
            arr[idx] = arr[idx<<1] + arr[idx<<1|1];
        }
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        SegTree* root = new SegTree(n);
        multimap<int,int> map;      // {num, index}
        for (int i = 0; i < nums.size(); i++) map.insert({nums[i], i});
        for (const auto p : map) {
            int num = p.first;
            int idx = p.second;
            res[idx] = root->count(idx);
            root->add(idx);
        }
        return res;
    }
};
// @lc code=end

