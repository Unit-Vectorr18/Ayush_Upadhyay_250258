#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int blue = nums.size() - 1;
        int cur = 0;

        while (cur <= blue) {
            if (nums[cur] == 0) {
                int temp = nums[red];
                nums[red] = nums[cur];
                nums[cur] = temp;
                red++;
                cur++;
            }
            else if (nums[cur] == 2) {
                int temp = nums[blue];
                nums[blue] = nums[cur];
                nums[cur] = temp;
                blue--;
            }
            else {
                cur++;
            }
        }
    }
};

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    Solution obj;
    obj.sortColors(nums);

    cout << "Sorted Colors: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}