#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> freq(1001, 0);
        vector<int> result;

        for (int i = 0; i < arr1.size(); i++) {
            freq[arr1[i]]++;
        }

        for (int j = 0; j < arr2.size(); j++) {
            while (freq[arr2[j]] > 0) {
                result.push_back(arr2[j]);
                freq[arr2[j]]--;
            }
        }
        for (int i = 0; i < 1001; i++) {
            while (freq[i] != 0) {
                result.push_back(i);
                freq[i]--;
            }
        }
        return result;
    }
};

int main() {
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};

    Solution obj;
    vector<int> result = obj.relativeSortArray(arr1, arr2);

    cout << "Relative Sorted Array: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}