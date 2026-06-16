#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n;

        for (int i = 0; i < n; i++) {
            ans ^= i;
            ans ^= nums[i];
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Missing Number: " << obj.missingNumber(nums) << endl;

    return 0;
}