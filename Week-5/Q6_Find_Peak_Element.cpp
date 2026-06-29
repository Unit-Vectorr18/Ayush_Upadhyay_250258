#include <iostream>
#include <vector>
using namespace std;
int findPeakElement(vector<int>& nums){
    long long low=0;
    long long high=nums.size()-1;
    while(low<high){
        long long mid=low+(high-low)/2;
        if(mid<nums.size()-1 && nums[mid]>nums[mid+1]){
            high=mid;
        }
        else{
            low=mid+1;

        }
        
    }
    return low;
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
    long long result=findPeakElement(nums);
    cout<<result<<endl;


    return 0;
}