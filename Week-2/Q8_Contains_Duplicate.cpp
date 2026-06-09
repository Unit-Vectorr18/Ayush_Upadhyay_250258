#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex;

        for (int i = 0; i < nums.size(); i++) {
            if (lastIndex.find(nums[i]) != lastIndex.end()) {
                if (i - lastIndex[nums[i]] <= k) {
                    return true;
                }
            }

            lastIndex[nums[i]] = i;
        }

        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    Solution obj;

    if (obj.containsNearbyDuplicate(nums, k))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}