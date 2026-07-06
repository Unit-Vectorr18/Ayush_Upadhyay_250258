#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
vector<bool> used;

void backtrack(int pos, int n) {

    if (pos > n) {
        ans++;
        return;
    }

    for (int num = 1; num <= n; num++) {

        if (!used[num] &&
            (num % pos == 0 || pos % num == 0)) {

            used[num] = true;

            backtrack(pos + 1, n);

            used[num] = false;
        }
    }
}

int main() {

    int n;
    cin >> n;

    used.resize(n + 1, false);

    backtrack(1, n);

    cout << ans;

    return 0;
}