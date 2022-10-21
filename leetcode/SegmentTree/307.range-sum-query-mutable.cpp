/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
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
    void build(vector<int>& nums) {
        for (int i = 0; i < n; i++)
            arr[i+m] = nums[i];
        for (int i = m-1; i; i--)
            arr[i] = arr[i<<1] + arr[i<<1|1];
    }
    void update(int i, int val) {
        int diff = val - arr[i+m];
        for (i+=m; i; i>>=1) arr[i] += diff;
    }
    int query(int left, int right) {
        int sum = 0;
        for (int i = left+m, j = right+m; i <= j; i >>= 1, j >>= 1) {
            if (i & 1) sum += arr[i++];
            if (~j & 1) sum += arr[j--];
        }
        return sum;
    }
};
class NumArray {
    SegTree* root;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        root = new SegTree(n);
        root->build(nums);
    }
    
    void update(int index, int val) {
        root->update(index, val);
    }
    
    int sumRange(int left, int right) {
        return root->query(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

