#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        vector<int> vec = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        unordered_map<int,string> map = {
         {1, "I"},{4, "IV"},{5, "V"},{9, "IX"},
         {10,"X"},{40,"XL"},{50,"L"},{90,"XC"},
         {100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}
        };
        string s;
        int i = 0;
        while (num > 0){
            while (num >= vec[i]){
                num -= vec[i];
                s = s + map[vec[i]];
            }
            i++;
        }
        return s;
    }

};
// @lc code=end


int main(){
    Solution sol;
    cout << sol.intToRoman(1994) << endl;
    return 0;
}

// M CM XC IV = 1994
// 1000
//  900
//   90
//    4
// I  = 1
// IV = 4
//  V = 5
// IX = 9
//  X = 10
// XL = 40
//  L = 50
// XC = 90
//  C = 100
// CD = 400
//  D = 500
// CM = 900
//  M = 1000



