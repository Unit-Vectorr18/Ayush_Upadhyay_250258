#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int m, n;

    bool dfs(vector<vector<char>>& board, string &word, int i, int j, int idx) {

        // All characters matched
        if (idx == word.size())
            return true;

        // Boundary or mismatch check
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[idx])
            return false;

        // Mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore 4 directions
        bool found = dfs(board, word, i + 1, j, idx + 1) ||
                     dfs(board, word, i - 1, j, idx + 1) ||
                     dfs(board, word, i, j + 1, idx + 1) ||
                     dfs(board, word, i, j - 1, idx + 1);

        // Backtrack
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> board(m, vector<char>(n));

    // Input board
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    string word;
    cin >> word;

    Solution obj;

    if (obj.exist(board, word))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}