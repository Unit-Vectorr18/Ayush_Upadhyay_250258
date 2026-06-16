#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        int n = arr.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int left = q[0];
            int right = q[1];

            ans.push_back(prefix[right + 1] ^ prefix[left]);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));

    cout << "Enter queries (left right):" << endl;
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<int> result = obj.xorQueries(arr, queries);

    cout << "Answers: ";
    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}