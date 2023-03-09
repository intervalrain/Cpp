#include <iostream>
#include <random>
#include <vector>

using namespace std;

class agtr{
public:
    static vector<int> exec(int n, int minv, int maxv) {
        if (minv > maxv) return {};
        else if (minv == maxv) return vector<int>(n, minv);
        vector<int> res;
        random_device rd;
        mt19937 mt(rd());
        uniform_real_distribution<double> dist(minv, maxv);
        while (n--) {
            res.push_back(dist(mt));
        }
        return res;
    }
    static vector<int> exec(int n) {
        return exec(n, 0, 10);
    }

    static vector<int> exec() {
        return exec(10);
    }
    static void print(vector<int>& nums) {
        cout << "[";
        for_each(nums.begin(), nums.end()-1, [](int x) { cout << x << ","; });
        cout << *(nums.end()-1) << "]";
    }
    static bool check(vector<int>& nums, vector<int> copy) {
        sort(copy.begin(), copy.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != copy[i]) return false;
        }
        return true;
    }
    static void judge(void (*func)(vector<int>&)) {
        int n = 10;
        bool test = true;
        int cnt = 0;
        while (n--) {
            auto nums = exec();
            auto copy = vector<int>(nums.begin(), nums.end());
            print(nums);
            (*func)(nums);
            cout << "->";
            print(nums);
            int result = check(nums, copy);
            cout << "(" << (result ? "Pass" : "Fail") << ")" << endl;
            if (result) cnt++;
            test &= result;
        }
        if (test) {
            cout << "Pass! (10/10)" << endl;
        } else {
            cout << "Fail! (" << cnt << "/10)" << endl;
        }
    }
};

