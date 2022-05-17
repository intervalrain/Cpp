#include <iostream>
#include <vector>
using namespace std;

/**
 * Minimum Platforms (Medium)
 *
 * Given arrival and departure times of all trains that reach a railway station.
 * Find the minimum number of platforms required for the railway station so that no train is kept waiting.
 *
 * Consider that all the trains arrive on the same day and leave on the same day.
 * Arrival and departure time can never be the same for a train but
 * we can have arrival time of one train equal to departure time of the other.
 * At any instance of time, same platform can not be used for both departure of a train and arrival of another train.
 * In such cases, we need different platforms.
 */

class Solution{
public:
    int findPlatform(int arr[], int dep[], int n){
        int i = 0, j = 0;
        int cnt = 0;
        sort(arr, arr+n);
        sort(dep, dep+n);
        while (i < n && j < n){
            if (arr[i] <= dep[j]){
                i++;
                cnt = max(i-j, cnt);
            } else {
                j++;
            }
        }

        return cnt;
    }
};

int main(){
    Solution* sol = new Solution;
    int arr1[] = { 900,  940,  950, 1100, 1500, 1800};
    int dep1[] = { 910, 1200, 1120, 1130, 1900, 2000};
    cout << sol->findPlatform(arr1, dep1, 6) << endl;

    int arr2[] = { 900, 1100, 1235};
    int dep2[] = {1000, 1200, 1240};
    cout << sol->findPlatform(arr2, dep2, 3) << endl;

    return 0;
}
