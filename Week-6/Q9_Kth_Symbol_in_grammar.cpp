#include <iostream>
using namespace std;

int kthGrammar(int n, int k) {

    if (n == 1)
        return 0;

    int mid = 1 << (n - 2);

    if (k <= mid)
        return kthGrammar(n - 1, k);

    return 1 - kthGrammar(n - 1, k - mid);
}

int main() {

    int n, k;
    cin >> n >> k;

    cout << kthGrammar(n, k);

    return 0;
}