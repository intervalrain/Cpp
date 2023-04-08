#include <bits/stdc++.h>

using namespace std;




//
//               o
//             o o
//           o   o
//         o o   o
//       o       o
//     o o       o
//   o   o       o
// o o   o       o
// 1 2 3 4 5 6 7 8
//
// 1 1 1 1 1 1 1 1 (arr)
//
// 1 2 1 4 1 2 1 8 (bit)
//     <---> +1
//
// 1 1 2 2 2 1 1 1 (arr)
//
// 1 2 2 6 2 3 1 11(bit)
//

class BIT {
private:
    vector<int> bit;
    vector<int> arr;
    int lowbit(int a) {
        return a & (-a);
    }
    int query(int index) {
        if (index < 0) return 0;
        int n = arr.size();
        index = min(index, n-1);
        index++;
        int sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= lowbit(index);
        }
        return sum;
    }
    void normalize(int& left, int& right) {
        if (left > right) swap(left, right);
        left = max(0, left);
        int n = arr.size();
        right = min(right, n-1);
    }
public:
    BIT (vector<int>& nums) {
        int n = nums.size();
        arr = nums;
        bit.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            bit.push_back(nums[i]);
            int idx = i+1;
            int lb = lowbit(idx);
            int j = idx - lb;
            while (lb > 1) {
                lb >>= 1;
                j |= lb;
                bit[idx] += bit[j];
            }
        }
    }

    BIT (int n) {
        arr.assign(n, 0);
        bit.assign(n+1, 0);
    }
    void update(int index, int val) {
        int ori = arr[index];
        int diff = val - ori;
        int n = bit.size();
        index++;
        while (index < n) {
            bit[index] += diff;
            index += lowbit(index);
        }
    }
    const int &operator[](int index) const {
        return arr[index];
    }
    const int at(int index) const {
        return arr[index];
    }
    const int getSum(int left, int right) {
        normalize(left, right);
        return query(right) - query(left-1);
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    BIT bit(nums);
    cout << bit.getSum(0,9) << endl;
    cout << bit.getSum(4,9) << endl;
    cout << bit.getSum(3,7) << endl;
    cout << bit.at(5) << endl;
    cout << bit[5] << endl;

    return 0;
}
