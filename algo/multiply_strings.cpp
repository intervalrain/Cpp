#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        vector<int> res(m+n, 0);
        for (int i = m-1; i >= 0; i++){
            for (int j = n-1; j >= 0; j++){
                char& a = num1[i];
                char& b = num2[j];
                int mul = (a-'0') * (b-'0');
                int p1 = i+j, p2 = i+j+1;
                int sum = mul + res[p2];
                res[p2] = sum % 10;
                res[p1] = sum / 10;
            }
        }
        int i = 0;
        while (i < res.size() && res[i] == 0){
            i++;
        }
        string str;
        for(; i < res.size(); i++){
            str.push_back('0' + res[i]);
        }
        return str.size() == 0 ? "0" : str;
    }
};

int main(){
    Solution* sol = new Solution();
    string num1 = "123", num2 = "456";
    string res = sol->multiply(num1, num2);

    cout << res << endl;
    return 0;
}

