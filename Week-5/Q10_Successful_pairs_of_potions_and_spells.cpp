#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

    sort(potions.begin(), potions.end());

    vector<int> result;

    for (int spell : spells) {

        int low = 0;
        int high = potions.size() - 1;
        int first = potions.size();

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (1LL * spell * potions[mid] >= success) {
                first = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        result.push_back(potions.size() - first);
    }

    return result;
}

int main() {

    int n, m;

    // Number of spells
    cin >> n;
    vector<int> spells(n);

    for (int i = 0; i < n; i++) {
        cin >> spells[i];
    }

    // Number of potions
    cin >> m;
    vector<int> potions(m);

    for (int i = 0; i < m; i++) {
        cin >> potions[i];
    }

    long long success;
    cin >> success;

    vector<int> ans = successfulPairs(spells, potions, success);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}