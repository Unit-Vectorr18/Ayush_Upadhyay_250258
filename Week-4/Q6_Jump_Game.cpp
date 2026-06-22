#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > reach)
                return false;

            reach = max(reach, i + nums[i]);
        }

        return true;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (obj.canJump(nums))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}