#include <iostream>
#include <vector>

/**
 * Given an image represented by an NxN matrix,
 * where each pixel in the image is represented by an integer,
 * write a method to rotate the image by 90 degrees.
 * Can you do this in place?
 */

using namespace std;

class Solution{
  public:
    bool rotate(vector<vector<int>>& matrix){
        if (matrix.size() == 0 || matrix.size() != matrix[0].size())
            return false;
        int n = matrix.size();
        for (int layer = 0; layer < n/2; layer++){
            int first = layer;
            int last = n - 1 - layer;
            for (int i = first; i < last; i++){
                int offset = i - first;
                int top = matrix[first][i];
                matrix[first][i] = matrix[last-offset][first];
                matrix[last-offset][first] = matrix[last][last-offset];
                matrix[last][last-offset] = matrix[i][last];
                matrix[i][last] = top;
            }
        }
        return true;
    }
    bool rotate2(vector<vector<int>>& matrix){
        if (matrix.size() == 0 || matrix.size() != matrix[0].size())
            return false;
        int n = matrix.size();
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        return true;
    }
};

void print(vector<vector<int>> matrix){
    int n = matrix.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void print(char c, int n){
    while(n--){
        cout << c;
    }
    cout << endl;
}


int main(){
    vector<vector<int>> matrix = {{1,2,3,4},
                                  {5,6,7,8},
                                  {9,10,11,12},
                                  {13,14,15,16}};
    Solution* sol = new Solution();

    print(matrix);
    print('-', 11);
    sol->rotate(matrix);

    print(matrix);
    print('-', 11);
    sol->rotate2(matrix);

    print(matrix);
    print('-', 11);
    return 0;
}
