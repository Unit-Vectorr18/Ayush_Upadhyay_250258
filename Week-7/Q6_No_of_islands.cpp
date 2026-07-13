#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& grid, int row, int col) {

    int m = grid.size();
    int n = grid[0].size();

    if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == '0')
        return;

  
    grid[row][col] = '0';

    // Visit all four directions
    dfs(grid, row - 1, col); 
    dfs(grid, row + 1, col); 
    dfs(grid, row, col - 1);
    dfs(grid, row, col + 1); 
}

int numIslands(vector<vector<char>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    int count = 0;

    for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++) {

            if (grid[i][j] == '1') {

                count++;

                dfs(grid, i, j);
            }
        }
    }

    return count;
}

int main() {

    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of Islands = " << numIslands(grid) << endl;

    return 0;
}