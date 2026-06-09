#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_Altitude = 0;
        int height = 0;
        for (int i = 0; i < gain.size(); i++) {
            height += gain[i];
            if (height > max_Altitude) {
                max_Altitude = height;
            }
        }
        return max_Altitude;
    }
};

int main() {
    vector<int> gain = {-5, 1, 5, 0, -7};

    Solution obj;

    cout << "Largest Altitude = "
         << obj.largestAltitude(gain) << endl;

    return 0;
}