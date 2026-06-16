#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int getNext(int n) {
        int sum = 0;

        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = getNext(n);
        }

        return n == 1;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (obj.isHappy(n))
        cout << n << " is a Happy Number" << endl;
    else
        cout << n << " is not a Happy Number" << endl;

    return 0;
}