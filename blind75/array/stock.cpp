#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices){
        int res = 0;
        int max_val = 0;
        for (int i = prices.size() - 1; i >=0; i--){
            max_val = max(max_val, prices[i]);
            res = max(res, max_val - prices[i]);
        }
        return res;
    }
};

int main(){
    Solution* sol = new Solution();
    int n;
    cout << "n = ";
    cin >> n;
    vector<int> prices(n, 0);
    cout << "prices = ";
    for (int i = 0; i < n; i++){
        cin >> prices[i];
    }

    cout << sol->maxProfit(prices) << endl;

    return 0;
}

