#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> Result;
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            if (numbers[left] == target - numbers[right]) {
                Result.push_back(left + 1);
                Result.push_back(right + 1);
                return Result;
            }
            else if (numbers[left] + numbers[right] < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return Result;
    }
};

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    Solution obj;
    vector<int> ans = obj.twoSum(numbers, target);

    cout << "Indices: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}