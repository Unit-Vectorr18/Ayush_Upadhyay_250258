#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> ans;

// Check whether a segment is valid
bool isValid(string part) {
    // Leading zero not allowed
    if (part.size() > 1 && part[0] == '0')
        return false;

    int num = stoi(part);

    return num >= 0 && num <= 255;
}

void backtrack(string &s, int index, int parts, string current) {

    // If 4 parts are formed
    if (parts == 4) {
        // Entire string should be used
        if (index == s.size()) {
            current.pop_back();      // Remove last '.'
            ans.push_back(current);
        }
        return;
    }

    // Try segments of length 1, 2, and 3
    for (int len = 1; len <= 3; len++) {

        if (index + len > s.size())
            break;

        string part = s.substr(index, len);

        if (isValid(part)) {
            backtrack(s,
                      index + len,
                      parts + 1,
                      current + part + ".");
        }
    }
}

int main() {

    string s;
    cin >> s;

    ans.clear();

    backtrack(s, 0, 0, "");

    if (ans.empty()) {
        cout << "No valid IP addresses\n";
    } else {
        cout << "Possible IP Addresses:\n";
        for (string ip : ans)
            cout << ip << endl;
    }

    return 0;
}