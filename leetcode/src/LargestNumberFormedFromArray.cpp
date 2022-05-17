#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Largest Number formed from an Array (Medium)
 *
 * Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.
 * The result if going to be very large,
 * hence return the result in the form of string.
 */

bool comp(string a, string b){
    int m = a.size();
    int n = b.size();
    int i;
    for (i = 0; i < min(m,n); i++){
        if (a[i] != b[i])
            return a[i] < b[i];
    }
    if (a.size() > b.size()){
        return a[i+1] < b[i];
    }
    return a[i] < b[i+1];
}

void push_back(string& sb, string word){
    for (int i = 0; i < word.length(); i++){
        sb.push_back(word[i]);
    }
}


class Solution{
public:
       string printLargest(vector<string> &arr){
        sort(arr.begin(), arr.end(), comp);
        string res = "";
        for (int i = 0; i < arr.size(); i++){
            push_back(res, arr[i]);
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

    return 0;
}

