#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool canShip(vector<int>& weights, int days, int capacity) {

    int requiredDays = 1;
    int currentWeight = 0;

    for (int weight : weights) {

        if (currentWeight + weight <= capacity) {
            currentWeight += weight;
        }
        else {
            requiredDays++;
            currentWeight = weight;
        }
    }

    return requiredDays <= days;
}

int shipWithinDays(vector<int>& weights, int days) {

    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    int ans = high;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (canShip(weights, days, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<int> weights(n);

    for (int i = 0; i < n; i++)
        cin >> weights[i];

    int days;
    cin >> days;

    cout << shipWithinDays(weights, days);

    return 0;
}