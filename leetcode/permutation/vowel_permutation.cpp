#include <iostream>
#include <list>
#include <queue>
#include <unordered_set>
#include <unordered_map>
/**
 *  a: e
 *  e: a, i
 *  i: a, e, o, u
 *  o: i, u
 *  u: a
 */

using namespace std;


class Solution{
  public:
    int MOD = 1000000007;
    int countVowelPermutation(int n){
        vector<long long int> prev = {1,1,1,1,1};
        vector<long long int> curr = {0,0,0,0,0};
        long long int cnt = 5;
        while (--n){
            curr[0] = (prev[1] + prev[2] + prev[4]) % MOD;
            curr[1] = (prev[0] + prev[2]) % MOD;
            curr[2] = (prev[1] + prev[3]) % MOD;
            curr[3] = (prev[2]) % MOD;
            curr[4] = (prev[2] + prev[3]) % MOD;
            cnt = 0;
            for (int i = 0; i < 5; i++){
                cnt %= MOD;
                cnt += (curr[i] % MOD);
            }
            prev = curr;
        }
        return (int)cnt;
    }
};

int main(){
    Solution* sol = new Solution();
    for (int i = 1; i <= 144; i++){
        cout << sol->countVowelPermutation(i) << endl;
    }
}
