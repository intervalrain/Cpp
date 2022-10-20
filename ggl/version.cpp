#include <bits/stdc++.h>
using namespace std;

struct apk_info{
    int apk_version;
    int min_version = 1;
    int max_version = INT_MAX;

    apk_info(int ver, int mn, int mx){
        this->apk_version = ver;
        this->min_version = mn;
        this->max_version = mx;
    }
};

class Solution {
  public:
  unordered_map<int, int> waitList;
    void remove(priority_queue<int>& pq, int item){
        if (pq.top() == item) {      // 若 pq 的頂是要移除的對象，則直接移除
            pq.pop();
            while (waitList.find(pq.top()) != waitList.end()  && waitList[pq.top()] > 0) {
                waitList[pq.top()]--;
                pq.pop();
            }
        } else {
            waitList[item]++;       // 若 pq 的頂非要移除的對象，則加入 waitList，待之後再移除
        }
    }
    vector<pair<int,int>> getRangeMax(vector<apk_info*> infos) {
        vector<pair<int,int>> rangeMax, osVers;
        for (const auto& info : infos) {
            osVers.push_back({info->min_version, -info->apk_version});   // 以負值代表 skyline 的開始
            osVers.push_back({info->max_version,  info->apk_version});   // 以正值代表 skyline 的結束
        }
        sort(osVers.begin(), osVers.end());     // 以 x 值(os_version) 進行排序
        priority_queue<int> pq;
        pq.push(0);                 // not found 時，預設回傳 0

        int prev = 0;               // 在還沒插入 item 前一開始的最大值就是 0
        for (const auto& osVer : osVers) {
            if (osVer.second < 0){      // 開始
                pq.push(-osVer.second);
            } else {                    // 結束，需移除該點
                remove(pq, osVer.second);
            }

            int curr = pq.top();
            if (prev != curr) {         // 若最大值有變，則需把 skyline 記錄下來
                if (prev < curr || osVer.first == INT_MAX)
                    rangeMax.push_back({osVer.first, curr});    // x 軸為 os version，y 軸為 apk version
                else                    // 為做成 [a, b) 左閉右開的區間，若 skyline 往下，x 軸的點位置需加 1 (版本以大的為主)
                    rangeMax.push_back({osVer.first+1, curr});
                prev = curr;
            }
        }
        return rangeMax;
    }
public:
    vector<int> findOSVersion(vector<apk_info*> infos, vector<int> queries) {
        vector<pair<int,int>> rangeMax = getRangeMax(infos);
        vector<int> res;
        for (const int& q : queries){
            auto it = upper_bound(rangeMax.begin(), rangeMax.end(), make_pair(q, INT_MAX));
            it--;
            res.push_back(it->second);
        }
        return res;
    }
};

int main(){
    apk_info* a1 = new apk_info(1, 14, INT_MAX);
    apk_info* a2 = new apk_info(2, 1, 8);
    apk_info* a3 = new apk_info(3, 12, 16);

    vector<apk_info*> infos = {a1, a2, a3};
    // vector<int> queries = {18, 4, 14, 10};    // 1, 2, 3, 0
    vector<int> queries = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    Solution* sol = new Solution();

    vector<pair<int,int>> skyline = sol->getRangeMax(infos);
    for (int i = 0; i < skyline.size(); i++){
        cout << "[" << skyline[i].first << "," << skyline[i].second << "]" << endl;
    }

    vector<int> res = sol->findOSVersion(infos, queries);
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

