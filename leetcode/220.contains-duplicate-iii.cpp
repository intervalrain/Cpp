// #include <bits/stdc++.h>

// using namespace std;

/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
		if (nums.size() < 2 || k < 1 || t < 0) return false;
		unordered_map<long long, long long> bucket;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > k) bucket.erase(((long long)nums[i - k - 1]  - INT_MIN) / ((long long)t + 1));
			long long num = (long long)nums[i] - INT_MIN;
			long long id = num / ((long long)t + 1);
			if (bucket.count(id)
				|| (bucket.count(id - 1) && nums[i] - bucket[id - 1] <= t)
				|| (bucket.count(id + 1) && bucket[id + 1] - nums[i] <= t))
				return true;
			bucket[id] = nums[i];
		}
		return false;
	}
    
};
// @lc code=end
