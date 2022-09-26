#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 */

// @lc code=start
class UF{
private:
    int count;
    vector<char> parent;
public:
    UF(int n){
        this->count = n;
        parent = vector<char>(n);
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    void unionAll(char a, char b){
        if (connected(a,b)) return;
        parent[find(a)] = find(b);
        count--;
    }
    bool connected(char a, char b){
        return find(a) == find(b);
    }
    int find(char x){
        if (parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UF uf(26);
        for (string& eq : equations){
            if (eq[1] == '='){
                char a = eq[0], b = eq[3];
                uf.unionAll(a - 'a', b - 'a');
            }
        }

        for (string& eq : equations){
            if (eq[1] == '!'){
                char a = eq[0], b = eq[3];
                if (uf.connected(a - 'a', b - 'a'))
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

