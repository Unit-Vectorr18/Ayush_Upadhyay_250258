#include <iostream>
#include <vector>
using namespace std;
int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int  mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[low]<=nums[mid]){
                if(target>=nums[low]&& target<nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(target>nums[mid]&& target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }

            }
        }
        return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums[i]=x;
    }
    int target;
    cin>>target;
    int result=search(nums,target);
    cout<<result<<endl;

    return 0;
}