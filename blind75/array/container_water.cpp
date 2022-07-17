#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxArea(vector<int>& height){
        int n = height.size();
        int left = 0, right = n-1;
        int area = 0;

        do {
            area = max(area, calArea(height, left, right));
            if (height[left] < height[right]){
                left++;
            } else {
                right--;
            }
        } while (left < right);

        return area;
    }

    int calArea(vector<int>& height, int left, int right){
        return min(height[left], height[right]) * (right - left);
    }
};

int main(){
    Solution* sol = new Solution();
    int n;
    cout << "n = ";
    cin >> n;
    vector<int> height(n, 0);
    for (int i = 0; i < n; i++){
        cin >> height[i];
    }
    cout << "max area = " << sol->maxArea(height) << endl;


    return 0;
    //
    //
    //  o    o
    //  o----o-o
    //  oo---o-o
    //  oo-o-o-o
    //  oo-ooo-o
    //  oo-ooooo
    //  oooooooo
    // ooooooooo
}
