#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long

using namespace std;

class Solution {
public:
    bool check(vector<ll> a, vector<ll> b, int n){
        unordered_map<int, int> mapa;
        unordered_map<int, int> mapb;
        for (int i = 0; i < n; i++){
            mapa[a[i]]++;
            mapb[b[i]]++;
        }
        if (mapa.size() != mapb.size()) return false;
        for (auto it = mapa.begin(); it != mapa.end(); it++){
            int key = it->first;
            int value = it->second;
            if (mapb[key] != value) return false;
        }
        return true;
    }
};

int main(){
    Solution* sol = new Solution();
    vector<ll> a1 = {1,2,5,4,0};
    vector<ll> b1 = {2,4,5,0,1};
    cout << sol->check(a1, b1, 5) << endl;   // true

    vector<ll> a2 = {1,2,5};
    vector<ll> b2 = {2,4,15};
    cout << sol->check(a2, b2, 3) << endl;   // false 

    vector<ll> a3 = {2,2};
    vector<ll> b3 = {3,3};
    cout << sol->check(a3, b3, 2) << endl;   // false;
}