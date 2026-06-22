#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cnt(5, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int taxis = cnt[4];

    taxis += cnt[3];
    cnt[1] = max(0, cnt[1] - cnt[3]);

    taxis += cnt[2] / 2;

    if (cnt[2] % 2) {
        taxis++;
        cnt[1] = max(0, cnt[1] - 2);
    }

    taxis += (cnt[1] + 3) / 4;

    cout << taxis << endl;
}