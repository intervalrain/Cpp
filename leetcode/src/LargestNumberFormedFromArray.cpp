#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

/**
 * Largest Number formed from an Array (Medium)
 *
 * Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.
 * The result if going to be very large,
 * hence return the result in the form of string.
 */

struct cmp{
    bool operator()(string a, string b){
        return a+b < b+a;
    }
};

class Solution{
public:
    static bool comp(string a, string b){
        return a+b > b+a;
    }
    // string printLargest(vector<string> &arr){
    //     sort(arr.begin(), arr.end(), comp);
    //     string res = "";
    //     for (size_t i = 0; i < arr.size(); i++){
    //         res += arr[i];
    //     }
    //     return res;
    // }
    string printLargest(vector<string> &arr){
        priority_queue<string, vector<string>, cmp> pq;
        for (size_t i = 0; i < arr.size(); i++)
            pq.push(arr[i]);
        string res = "";
        for (size_t i = 0; i < arr.size(); i++){
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};

int main(){
    Solution* sol = new Solution;
    vector<string> arr1 = {"3","30","34","5","9"};
    cout << sol->printLargest(arr1) << endl;     // 9534330

    vector<string> arr2 = {"54", "546", "548", "60"};
    cout << sol->printLargest(arr2) << endl;     // 6054854654

    vector<string> arr3 = {"2","197","229"};
    cout << sol->printLargest(arr3) << endl;     // 2292197


    return 0;
}

