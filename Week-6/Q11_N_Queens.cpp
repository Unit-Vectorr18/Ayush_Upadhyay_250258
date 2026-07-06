#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> ans;

vector<int> col;
vector<int> diag1;
vector<int> diag2;

void backtrack(int row, int n, vector<string>& board) {

    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int c = 0; c < n; c++) {

        if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
            continue;

        board[row][c] = 'Q';

        col[c] = 1;
        diag1[row - c + n - 1] = 1;
        diag2[row + c] = 1;

        backtrack(row + 1, n, board);

        board[row][c] = '.';

        col[c] = 0;
        diag1[row - c + n - 1] = 0;
        diag2[row + c] = 0;
    }
}

int main() {

    int n;
    cin >> n;

    vector<string> board(n, string(n, '.'));

    col.assign(n, 0);
    diag1.assign(2 * n - 1, 0);
    diag2.assign(2 * n - 1, 0);

    backtrack(0, n, board);

    for (auto &solution : ans) {
        for (auto &row : solution)
            cout << row << endl;
        cout << endl;
    }

    return 0;
}