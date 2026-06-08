#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int left_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int right_sum = sum - left_sum - nums[i];
            if (left_sum == right_sum) {
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};

    Solution obj;
    int pivot = obj.pivotIndex(nums);

    cout << "Pivot Index: " << pivot << endl;

    return 0;
}