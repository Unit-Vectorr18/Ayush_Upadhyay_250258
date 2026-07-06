#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;

    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void backtrack(string &s, int start) {
        if (start == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1);
                path.pop_back(); // Backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        ans.clear();
        path.clear();
        backtrack(s, 0);
        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cin >> s;

    vector<vector<string>> result = obj.partition(s);

    cout << "[\n";
    for (auto &partition : result) {
        cout << "  [";
        for (int i = 0; i < partition.size(); i++) {
            cout << "\"" << partition[i] << "\"";
            if (i != partition.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }
    cout << "]\n";

    return 0;
}