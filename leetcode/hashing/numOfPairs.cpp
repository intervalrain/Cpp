#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Number of pairs (Medium)
 *
 * Given two arrays x and y of positive integers,
 * find the number of pairs such that x^y > y^x (raised to power of) where
 * x is an element from x and y is an element from y.
 */
class Solution{
public:
    long long countPairs(vector<int> x, vector<int> y, int m, int n){
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        unordered_map<int,int> map;

        for (int i = 0; i < m; i++){
            if (x[i] == 1) map[1]++;
            if (x[i] == 3) {
              map[2]++;
              map[4]++;
            }
            if (x[i] > 3) break;
        }
        map[1] = m - map[1];
        map[3] = 0;

        long long res = 0;

        for (int i = 0; i < n; i++){
            if (map.count(y[i])){
                res += map[y[i]];
            } else {
                map[y[i]] = upper_bound(x.begin(), x.end(), y[i]-1) - x.begin() - (m - map[1]);
                res += map[y[i]];
            }
        }
        return res;
    }
};

int main(){
    Solution* sol = new Solution;

    vector<int> x1 = {2,1,6};
    vector<int> y1 = {1,5};
    int m1 = 3;
    int n1 = 2;
    cout << sol->countPairs(x1, y1, m1, n1) << endl;   // 3

    vector<int> x2 = {2,3,4,5};
    vector<int> y2 = {1,2,3};
    int m2 = 4;
    int n2 = 3;
    cout << sol->countPairs(x2, y2, m2, n2) << endl;   // 5

    return 0;
}
