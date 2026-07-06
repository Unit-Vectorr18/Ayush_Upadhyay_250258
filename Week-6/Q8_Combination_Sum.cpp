#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans;
vector<int> path;

void backtrack(int start, int k, int target) {

    // Found a valid combination
    if (target == 0 && path.size() == k) {
        ans.push_back(path);
        return;
    }

    // Invalid case
    if (target < 0 || path.size() >= k)
        return;

    for (int i = start; i <= 9; i++) {

        // Pruning
        if (i > target)
            break;

        path.push_back(i);

        backtrack(i + 1, k, target - i);

        path.pop_back();   // Backtrack
    }
}

int main() {

    int k, n;
    cin >> k >> n;

    backtrack(1, k, n);

    if (ans.empty()) {
        cout << "No valid combinations\n";
    } else {
        cout << "Valid combinations:\n";
        for (auto &v : ans) {
            cout << "[ ";
            for (int x : v)
                cout << x << " ";
            cout << "]\n";
        }
    }

    return 0;
}