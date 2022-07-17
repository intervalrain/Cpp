#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
    bool containsDuplicate(vector<int>& nums){
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++){
            if (set.count(nums[i])){
                return true;
            }
            set.insert(nums[i]);
        }
        return false;
    }
};

int main(){
    Solution* sol = new Solution();
    int n;
    cout << "n = ";
    cin >> n;
    vector<int> nums(n, 0);
    cout << "nums = ";
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << (sol->containsDuplicate(nums) ? "True" : "False") << endl;

    return 0;
}
