#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for (int n : nums) {
            if (set.count(n))
                return true;
            set.insert(n);
        }

        return false;
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

    if (obj.containsDuplicate(nums))
        cout << "Contains Duplicate" << endl;
    else
        cout << "Does Not Contain Duplicate" << endl;

    return 0;
}