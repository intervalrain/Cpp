#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxArea(vector<int>& height){
        int l = 0, r = height.size() - 1;
        int area = 0;
        do {
            area = max(area, calArea(height, l, r));
            if (height[l] < height[r])
                l++;
            else
                r--;
        } while (l < r);
        return area;
    }

    int calArea(vector<int>& height, int a, int b){
        return min(height[a],height[b])*abs(a-b);
    }
};

int main(){
    Solution* sol = new Solution();
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << sol->maxArea(height) << endl;

    return 0;
}