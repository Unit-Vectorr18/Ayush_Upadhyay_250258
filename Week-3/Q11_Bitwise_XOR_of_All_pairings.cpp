#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        int ans = 0;

        if (nums2.size() % 2 == 1) {
            for (int num : nums1)
                ans ^= num;
        }

        if (nums1.size() % 2 == 1) {
            for (int num : nums2)
                ans ^= num;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n1, n2;

    cout << "Enter size of nums1: ";
    cin >> n1;

    vector<int> nums1(n1);

    cout << "Enter elements of nums1: ";
    for (int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }

    cout << "Enter size of nums2: ";
    cin >> n2;

    vector<int> nums2(n2);

    cout << "Enter elements of nums2: ";
    for (int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }

    cout << "Result: " << obj.xorAllNums(nums1, nums2) << endl;

    return 0;
}