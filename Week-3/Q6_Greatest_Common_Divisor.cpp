#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int findGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1)
            return "";

        int len = findGCD(str1.size(), str2.size());

        return str1.substr(0, len);
    }
};

int main() {
    Solution obj;

    string str1, str2;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    cout << "GCD of Strings: "
         << obj.gcdOfStrings(str1, str2)
         << endl;

    return 0;
}