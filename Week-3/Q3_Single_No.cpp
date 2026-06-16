#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            ans ^= nums[i];
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Single Number: " << obj.singleNumber(nums) << endl;

    return 0;
}