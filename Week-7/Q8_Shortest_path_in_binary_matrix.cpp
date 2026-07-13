#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

    int n = grid.size();

    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return -1;

    queue<pair<int,int>> q;

    q.push({0,0});

    grid[0][0] = 1;

    int dr[] = {-1,-1,-1,0,0,1,1,1};
    int dc[] = {-1,0,1,-1,1,-1,0,1};

    while(!q.empty()){

        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        int dist = grid[row][col];

        if(row == n-1 && col == n-1)
            return dist;

        for(int i=0;i<8;i++){

            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if(newRow>=0 && newRow<n &&
               newCol>=0 && newCol<n &&
               grid[newRow][newCol]==0){

                grid[newRow][newCol] = dist + 1;
                q.push({newRow,newCol});
            }
        }
    }

    return -1;
}

int main(){

    vector<vector<int>> grid = {
        {0,1},
        {1,0}
    };

    cout << shortestPathBinaryMatrix(grid);

    return 0;
}