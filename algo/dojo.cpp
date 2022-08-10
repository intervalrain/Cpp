#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<pair<int,int>> solve(vector<int> nums1, vector<int> nums2, int target){
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<pair<int,int>> res;
        unordered_map<int, vector<pair<int,int>>> map;
        int mindiff = INT_MAX;

        int row = 0, col = n-1;
        while (row < n && col >= 0){
            int num = nums1[row] + nums2[col];
            int diff = num - target;
            if (diff == 0){
                map[abs(diff)].push_back({nums1[row], nums2[col]});
                mindiff = 0;
                row++;
                col--;
            } else if (diff < 0){
                map[abs(diff)].push_back({nums1[row], nums2[col]});
                mindiff = min(mindiff, abs(diff));
                row++;
            } else {
                map[abs(diff)].push_back({nums1[row], nums2[col]});
                mindiff = min(mindiff, abs(diff));
                col--;
            }
        }
        return map[mindiff];
    }
};

int main(){
    vector<int> nums1 = {-1,3,8,2,9,5};
    vector<int> nums2 = {4,1,2,10,5,20};
    int target = 24;  // {5,20}, {3,20}

    Solution* sol = new Solution();
    vector<pair<int,int>> res = sol->solve(nums1, nums2, target);
    
    for (auto p : res){
        cout << "{" << p.first << "," << p.second << "}" << endl;
    }

    delete sol;

    return 0;
}
