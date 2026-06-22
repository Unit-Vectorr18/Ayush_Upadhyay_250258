#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        if (points.empty())
            return 0;

        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int arrows = 1;
        long long end = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > end) {
                arrows++;
                end = points[i][1];
            }
        }

        return arrows;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of balloons: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    cout << "Enter balloon intervals (start end):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    cout << "Minimum arrows required: "
         << obj.findMinArrowShots(points)
         << endl;

    return 0;
}