#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;

        for (char c : s)
            ans ^= c;

        for (char c : t)
            ans ^= c;

        return ans;
    }
};

int main() {
    Solution obj;

    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    cout << "Extra character: " << obj.findTheDifference(s, t) << endl;

    return 0;
}