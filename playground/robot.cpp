#include <iostream>
#include <unistd.h>
#include <vector>
#include <unordered_set>

using namespace std;

void print(vector<vector<int>>& grid, int d) {
    getchar();
    system("clear");

    string sign;
    if (d == 0) sign = "▲";
    else if (d == 1) sign = "▶";
    else if (d == 2) sign = "▼";
    else if (d == 3) sign = "◀";
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
           if (grid[i][j] == 2) cout << sign;
           else if (grid[i][j] == 1) cout << "■";
           else cout << "□";
        }
        cout << endl;
    }
}

int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void dfs(vector<vector<int>>& grid, unordered_set<string>& set, int x, int y, int d) {
    grid[x][y] = 2;
    print(grid, d);
    grid[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int j = (d + i) % 4;
        int dx = x + dir[j][0];
        int dy = y + dir[j][1];
        string ds = to_string(dx) + "," + to_string(dy);
        if (!set.count(ds) && dx >= 0 && dy >= 0 && dx < grid.size() && dy < grid[0].size() && grid[dx][dy] == 0) {
            set.insert(ds);
            dfs(grid, set, dx, dy, j);
        }
    }
}

int main() {
    system("clear");
    vector<vector<int>> grid = {
        {0,0,0,0,0,1,0,0,1},
        {0,0,0,0,0,1,0,0,0},
        {0,1,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1},
        {0,1,1,0,0,0,1,1,0},
        {0,0,0,0,0,0,0,0,0}
    };
    unordered_set<string> set;
    dfs(grid, set, 1, 3, 0);

    return 0;
}
