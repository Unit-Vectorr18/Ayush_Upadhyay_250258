#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> ans;

    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs",
        "tuv", "wxyz"
    };

    void solve(string &digits, int idx, string &curr) {

        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[idx] - '0'];

        for (char ch : letters) {
            curr.push_back(ch);
            solve(digits, idx + 1, curr);
            curr.pop_back();      // Backtrack
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        string curr = "";
        solve(digits, 0, curr);

        return ans;
    }
};

int main() {

    Solution obj;

    string digits;
    cout << "Enter digits (2-9): ";
    cin >> digits;

    vector<string> result = obj.letterCombinations(digits);

    cout << "Possible combinations:\n";

    for (string s : result) {
        cout << s << " ";
    }

    cout << endl;

    return 0;
}