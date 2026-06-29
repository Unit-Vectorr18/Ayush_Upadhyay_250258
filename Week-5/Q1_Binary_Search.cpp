#include <bits/stdc++.h>
using namespace std;
int Search(vector <int> &nums,int target){
    int n=nums.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;

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
    int result=Search(nums,target);
    cout<<result<<endl;




    return 0;
}