#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        int mid;
        while (true){
            mid = left + (right - left)/2;
            int res = guess(mid);
            if (res == 0){
                break;
            } else if (res == 1){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return mid;
    }
};
// @lc code=end

