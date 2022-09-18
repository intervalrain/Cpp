#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 */

// @lc code=start
class Solution {
    class node {
        public:
        int idx;
        node *nxt[26];
        node () : idx(0), nxt{0} {}
    };
    
    static void solve(const vector<string>& words, vector<vector<int>>& ret, const vector<vector<int>>& Manacher, const int h, node *memPool) {
        const int m = size(words);
        node root;
        for (int i = 0; i < m; ++i) {
            auto& s = words[i];
            auto p = &root;
            for (auto c : s)
                if (nullptr == p->nxt[c - 'a'])
                    p = p->nxt[c - 'a'] = memPool++;
                else
                    p = p->nxt[c - 'a'];
            p->idx = i + 1;
        }
        for (int i = 0; i < m; ++i) {
            auto& s = words[i];
            auto& dp = Manacher[i];
            const int n = size(s);
            auto p = &root;
            if (0 == h && dp[n] == n && p->idx && p->idx != i + 1) {
                ret.push_back({p->idx - 1, i});
                ret.push_back({i, p->idx - 1});
            }
            for (int j = n - 1; j >= h; --j) {
                if (nullptr == p->nxt[s[j] - 'a'])
                    break;
                p = p->nxt[s[j] - 'a'];
                if (p->idx && p->idx != i + 1 && dp[j] == j)
                    if (h)
                        ret.push_back({i, p->idx - 1});
                    else
                        ret.push_back({p->idx - 1, i});
            }
        }
    }
     
public:
    static vector<vector<int>> palindromePairs(vector<string>& words) {
        const int m = size(words);
        size_t fullSize = 0;
        vector<vector<int>> Manacher(m);
        
        for (int i = 0; i < m; ++i) {
            auto& s = words[i];
            auto& dp = Manacher[i];
            const int n = size(s);
            fullSize += n;
            dp.resize(2 * n + 1);
            string v(2 * n + 1, '#');
            for (int i = 0; i < n; ++i)
                v[2 * i + 1] = s[i];
            int C = 0;
            for (int ii = 1; ii < 2 * n; ++ii) {
                if (ii - C < + dp[C])
                    dp[ii] = min(dp[2 * C - ii], dp[C] + C - ii);
                while(ii - dp[ii] > 0 &&
                      ii + dp[ii] + 1 < 2 * n + 1 &&
                      v[ii - dp[ii] - 1] == v[ii + dp[ii] + 1])
                    ++dp[ii];
                if (ii + dp[ii] > C + dp[C])
                    C = ii;
            }
        }
        
        auto memPool = new node[fullSize];
        vector<vector<int>> ret;
        solve(words, ret, Manacher, 0, memPool);
        for (int i = 0; i < m; ++i) {
            reverse(begin(words[i]), end(words[i]));
            reverse(begin(Manacher[i]), end(Manacher[i]));
        }
        memset(memPool, 0, fullSize * sizeof(node));
        solve(words, ret, Manacher, 1, memPool);
        delete[] memPool;
        return ret;
    }
};
// @lc code=end

