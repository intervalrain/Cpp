#include <iostream>
using namespace std;


class Solution{
  public:
    uint32_t reverseBits(uint32_t n){
        uint32_t res = 0;
        for (int i = 0; i < 32; i++){
            res = (res << 1) | (n & 1);
            n >>= 1;
        }
        return res;
    }
};

int main(){
    uint32_t n;
    cout << "n = ";
    cin >> n;
    Solution* sol = new Solution();
    cout << sol->reverseBits(n);

    return 0;
}
