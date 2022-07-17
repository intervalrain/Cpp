#include <iostream>

using namespace std;

class Solution{
  public:
    int hammingWeight(int n){
        int cnt = 0;
        while (n != 0){
            cnt++;
            n &= (n-1);
        }
        return cnt;
    }
};

//   11101010111
//   11101010110
//   -----------
//   11101010110
//   11101010101
//   -----------
//   11101010100
//   11101010011
//   -----------
//   11101010000
//   11101001111

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    Solution* sol = new Solution();
    cout << sol->hammingWeight(n) << endl;

    return 0;
}

