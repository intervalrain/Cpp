#include <iostream>

using namespace std;

class Solution{
  public:
    int getSum(int a, int b){
        while (b != 0){
            int sum = a ^ b;
            unsigned cin = a & b;
            a = sum;
            b = cin << 1; // (cin & mask) << 1,   mask = ~INT_MIN
        }
        return a;
    }
};

int main(){
    Solution* sol = new Solution();
    int a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    cout << sol->getSum(a, b) << endl;

    return 0;
}
