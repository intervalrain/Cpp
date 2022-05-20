#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**
 * Sorting Elements of an Array by Frequency (Medium)
 *
 * Given an array arr[] of integers,
 * sort the array according to frequency of elements.
 * That is elements that have higher grequency come first.
 * If frequencies of two elements are same,
 * then smaller number comes first.
 *
 * The first line of input contains an integer T denoting the number of test cases.
 * The description of T test cases follows.
 * The first line of each test case contains a single integer N denoting the size of array.
 * The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
 *
 * For each testcase, in a new line, print each sorted array in a separate line.
 * For each array its number should be seperated by space.
 */

bool compare(pair<int,int> p1, pair<int,int> p2){
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

class Solution{
public:
    void sortByFreq(int arr[], int n){
        unordered_map<int, int> map;
        vector<pair<int, int> > vec;
        for (int i = 0; i < n; i++){
            map[arr[i]]++;
        }
        for (auto it = map.begin(); it != map.end(); it++){
            vec.push_back(make_pair(it->first, it->second));
        }
        sort(vec.begin(), vec.end(), compare);
        int cnt = 0;
        for (auto it = vec.begin(); it != vec.end(); it++){
            for (int i = 0; i < it->second; i++){
                arr[cnt++] = it->first;
            }
        }
    }
};

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, i;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        Solution ob;
        ob.sortByFreq(arr, n);
        printArray(arr, n);
    }
    return 0;
}
