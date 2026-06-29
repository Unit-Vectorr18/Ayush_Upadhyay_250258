#include <iostream>
using namespace std;
int arrangeCoins(int n){
    long long low=0;
    long long high=n;
    while(low<=high){
        long long mid=low+(high-low)/2;
        long long sum=mid*(mid+1)/2;
        if(sum==n){
            return mid;
        }
        else if(sum<n){
            low=mid+1;
        }
        else{
            high=mid-1;
        }

    }
    return high;
}
int main(){
    int n;
    cin>>n;
    long long result=arrangeCoins(n);
    cout<<result<<endl;




    return 0;
}