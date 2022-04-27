#include <iostream>
#include <vector>

#define MAX_VAL (2147483647)

using namespace std;

class Solution{
public:
    int minCost(vector<vector<int> >& points){
        int n = points.size();
        int res = 0;
        int mins[n];
        bool connected[n];
        for (int k = 0; k < n; ++k){
            mins[k] = MAX_VAL;
            connected[k] = false;
        }

        int i = 0;
        connected[i] = true;
        int cnt = 1;
        int next = 0;

        while (cnt < n){
            int min = MAX_VAL;
            for (int j = 0; j < n; ++j){
                if (connected[j]) continue;
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                mins[j] = mins[j] > dist ? dist : mins[j];
                if (min > mins[j]){
                    min = mins[j];
                    next = j;
                }
            }
            connected[next] = true;
            i = next;
            res += min;
            cnt++;
        }

        return res;
    }
};

int main(){
    Solution* sol = new Solution();

    vector<vector<int> > points{{0,0}, {2,2}, {3,10}, {5,2}, {7,0}};
    cout << sol->minCost(points) << endl;

    return 0;
}
