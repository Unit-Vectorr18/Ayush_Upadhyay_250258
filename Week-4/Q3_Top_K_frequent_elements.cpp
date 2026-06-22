#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int n : nums)
            freq[n]++;

        priority_queue<pair<int, int>> pq;

        for (auto &p : freq)
            pq.push({p.second, p.first});

        vector<int> ans;

        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
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

    int k;
    cout << "Enter k: ";
    cin >> k;

    vector<int> result = obj.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";

    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}