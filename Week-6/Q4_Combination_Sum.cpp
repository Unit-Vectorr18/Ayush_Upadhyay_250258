#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(int idx, vector<int>& candidates, int target) {

        // Found a valid combination
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        // No more candidates
        if (idx == candidates.size())
            return;

        // Take current candidate
        if (candidates[idx] <= target) {
            curr.push_back(candidates[idx]);
            solve(idx, candidates, target - candidates[idx]); // Same index (reuse allowed)
            curr.pop_back(); // Backtrack
        }

        // Don't take current candidate
        solve(idx + 1, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, candidates, target);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of candidates: ";
    cin >> n;

    vector<int> candidates(n);

    cout << "Enter candidates: ";
    for (int i = 0; i < n; i++)
        cin >> candidates[i];

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    vector<vector<int>> result = obj.combinationSum(candidates, target);

    cout << "\nPossible combinations:\n";

    for (auto &vec : result) {
        cout << "[ ";
        for (int x : vec)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}