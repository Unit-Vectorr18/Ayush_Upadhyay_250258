#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long window_sum = 0;
        for (int i = 0; i < k; i++) {
            window_sum += nums[i];
        }
        long long maxSum = window_sum;
        for (int i = k; i < nums.size(); i++) {
            window_sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, window_sum);
        }

        return (double)maxSum / k;
    }
};

int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    Solution obj;

    cout << "Maximum Average = "
         << obj.findMaxAverage(nums, k) << endl;

    return 0;
}