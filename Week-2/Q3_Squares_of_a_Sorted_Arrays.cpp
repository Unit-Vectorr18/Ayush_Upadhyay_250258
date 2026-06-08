#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> squares(n);

        int left = 0;
        int right = n - 1;
        int cur = n - 1;

        while (left <= right) {
            long long left_sq = (long long)nums[left] * nums[left];
            long long right_sq = (long long)nums[right] * nums[right];

            if (left_sq > right_sq) {
                squares[cur] = left_sq;
                left++;
            } 
            else {
                squares[cur] = right_sq;
                right--;
            }

            cur--;
        }

        return squares;
    }
};

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};

    Solution obj;
    vector<int> result = obj.sortedSquares(nums);

    cout << "Sorted Squares: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}