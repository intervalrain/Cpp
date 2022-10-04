/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        // y = x/y
        if (x == 0) return 0;
        int left = 1, right = x;
        while (true){
            int mid = left + (right-left)/2;
            if (mid == x/mid){
                return mid;
            } else if (mid > x/mid){
                right = mid - 1;
            } else {
                if (mid+1 > x/(mid+1)) return mid;
                left = mid + 1;
            }
        }
        return left;
    }
    // 1,2 -> 2(1)
    // 1,1 -> 
};
// @lc code=end

// 1 : 1
// 2 : 1
// 3 : 1
// 4 : 2
// 5 : 2
// 9 : 3
//16 : 4
//25 : 5
//36 : 6

