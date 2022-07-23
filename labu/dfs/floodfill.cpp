#include <iostream>
#include <vector>

using namespace std;

// backtrack

class Solution{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int row, int col, int color) {
        int oColor = image[row][col];
        fill(image, row, col, oColor, -1);
        changeColor(image, -1, color);
        return image;
    }
private:
    void fill(vector<vector<int>>& image, int row, int col, int oColor, int color){
        if (outOfBound(image, row, col)) return;
        if (image[row][col] != oColor) return;
        image[row][col] = color;
        vector<vector<int>> dirc = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto d: dirc){
            fill(image, row + d[0], col + d[1], oColor, color);
        }   
    }
    bool outOfBound(vector<vector<int>>& image, int row, int col){
        int m = image.size();
        int n = image[0].size();
        return row < 0 || row >= m || col < 0 || col >= n;
    }
    void changeColor(vector<vector<int>>& image, int from, int to){
        for (int i = 0; i < image.size(); i++){
            for (int j = 0; j < image[0].size(); j++){
                if (image[i][j] == from){
                    image[i][j] = to;
                }
            }
        }
    }
};

void print(vector<int> vec){
    int n = vec.size();
    cout << "[";
    for (int i = 0; i < n-1; i++){
        cout << vec[i] << ",";
    }
    cout << vec[n-1] << "]" << endl;
}

void print(vector<vector<int>> vec){
    for (auto v : vec){
        print(v);
    }
}

int main(){
    vector<vector<int>> image = {{1,1,1,1,1},
                                 {1,1,0,1,1},
                                 {1,0,1,0,0},
                                 {0,1,0,1,1},
                                 {1,0,1,1,0}};
    print(image);
    Solution* sol = new Solution();
    vector<vector<int>> res = sol->floodFill(image, 1, 1, 2);
    for (int i = 0; i < image.size()*2+1; i++) cout << "-";
    cout << endl;
    print(res);

    return 0;
}