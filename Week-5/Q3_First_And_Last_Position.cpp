#include <iostream>
#include <vector>
using namespace std;
int start(vector <int>&nums,int target){
    int start=-1;
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            start=mid;
            high=mid-1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return start;
}
int end(vector <int>&nums,int target){
    int end=-1;
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            end=mid;
            low=mid+1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        
        }
        else{
            high=mid-1;
        }
        
    }
    return end;
}
vector<int> searchRange(vector<int>& nums, int target) {
       vector <int>result(2);
       result[0]=start(nums,target);
       result[1]=end(nums,target);
       return result;

        
}
int main(){
    int n;
    cin>>n;
    vector <int> nums(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums[i]=x;
    }
    int target;
    cin>>target;
    vector <int> result=searchRange(nums,target);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }




    return 0;
}