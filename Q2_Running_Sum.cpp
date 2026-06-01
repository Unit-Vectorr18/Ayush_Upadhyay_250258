#include <iostream>
#include <vector>
using namespace std;
class Solution { //Leetcode Running_sum function
public:
    vector<int> runningSum(vector<int>& nums) {
        vector <int> sum_arr;
        sum_arr.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            sum_arr.push_back(sum_arr[i-1]+nums[i]);
        }
        return sum_arr;
    }
};
int main(){ //Main function
    vector<int> nums={1,2,3,4};

    Solution s;
    vector<int> ans=s.runningSum(nums);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}