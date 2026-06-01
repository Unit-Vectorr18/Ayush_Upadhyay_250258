#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int exp_sum = (n * (n + 1)) / 2;

        int arr_sum = 0;
        for (int i = 0; i < n; i++) {
            arr_sum += nums[i];
        }

        return exp_sum - arr_sum;
    }
};

int main() {
    vector<int> nums = {3, 0, 1};

    Solution obj;
    cout << "Missing Number: " << obj.missingNumber(nums) << endl;

    return 0;
}