#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void solve(int idx, vector<int>& nums) {

        // Base case
        if (idx == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // Take the current element
        subset.push_back(nums[idx]);
        solve(idx + 1, nums);

        // Backtrack
        subset.pop_back();

        // Don't take the current element
        solve(idx + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution obj;
    vector<vector<int>> result = obj.subsets(nums);

    cout << "\nAll subsets are:\n";

    for (auto &v : result) {
        cout << "[ ";
        for (int x : v)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}