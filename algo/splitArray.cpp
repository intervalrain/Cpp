#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
  public:
    void subArr(vector<int>& nums){
        unordered_map<int,int> freq;
        unordered_map<int,vector<vector<int>>> need;

        for (int x : nums) freq[x]++;

        for (int x : nums){
            if (freq[x] == 0) continue;
            if (need.count(x) && need[x].size() > 0){
                freq[x]--;
                vector<int> seq = need[x].back();
                need[x].pop_back();
                seq.push_back(x);
                need[x+1].push_back(seq);
            } else if (freq[x] > 0 && freq[x+1] > 0 && freq[x+2] > 0){
                freq[x]--;
                freq[x+1]--;
                freq[x+2]--;
                vector<int> seq{x, x+1, x+2};
                need[x+3].push_back(seq);
            } else {
                break;
            }
        }
        for (auto it : need){
            for (vector<int>& seq : it.second){
                for (int v : seq){
                    cout << v << " ";
                }
                cout << endl;
            }
        }

    }
    // 1,2,3,4,5
    //     3,4,5
};

int main(){
    Solution* sol = new Solution();
    int n;
    cout << "Please input the numbers of elements in array." << endl;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sol->subArr(nums);

    return 0;
}
