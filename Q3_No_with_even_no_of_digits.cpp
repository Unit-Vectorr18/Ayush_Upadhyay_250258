#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
int no_of_digits(int n){
    int digit=0;
    while(n>0){
        digit++;
        n=n/10;
    }
    return digit;
}
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(no_of_digits(nums[i])%2==0){
                count++;
            }
        }
        return count;
        
    }
};
int main(){
    vector<int> nums={12,345,2,6,7896};

    Solution s;
    int ans=s.findNumbers(nums);

    cout<<ans;

    return 0;
}