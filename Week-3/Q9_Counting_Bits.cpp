#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }

        return dp;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> result = obj.countBits(n);

    cout << "Count of set bits from 0 to " << n << ":" << endl;

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}