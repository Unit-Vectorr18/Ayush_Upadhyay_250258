#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while (n) {
            count += (n & 1);
            n >>= 1;
        }

        return count;
    }
};

int main() {
    Solution obj;
    
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    cout << "Number of 1 bits: " << obj.hammingWeight(n) << endl;

    return 0;
}