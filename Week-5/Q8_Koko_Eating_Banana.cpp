#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minEatingSpeed(vector<int>& piles, int h) {
    long long low=1;
    long long high=*max_element(piles.begin(), piles.end());
    long long ans=high;
    while(low<=high){
        long long mid=low+(high-low)/2;
        long long hours=0;
        for(int pile:piles){
            hours += (pile + mid - 1) / mid;
        }
        if (hours <= h) {
                ans = mid;
                high = mid - 1;
        }
        else {
            low = mid + 1;
        }

    }
    return ans;
}
int main(){
    int h,n;
    cin>>n;
    vector <int> piles(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        piles[i]=x;
    }
    cin>>h;
    int result=minEatingSpeed(piles,h);
    cout<<result;


    return 0;
}