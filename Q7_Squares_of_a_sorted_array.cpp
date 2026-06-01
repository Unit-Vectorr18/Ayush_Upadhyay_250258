#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>squares={};
        for(int i=0;i<nums.size();i++){
            int d=nums[i]*nums[i];
            squares.push_back(d);
        }
        sort(squares.begin(),squares.end());
        return squares;
        
    }
};
int main(){
    vector<int> nums={-4,-1,0,3,10};

    Solution s;
    vector<int> ans=s.sortedSquares(nums);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
