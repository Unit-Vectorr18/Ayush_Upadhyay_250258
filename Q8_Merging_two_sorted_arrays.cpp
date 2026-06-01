#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[i-m];
        }

        sort(nums1.begin(),nums1.end());
        return;
    }
};

int main(){
    vector<int> nums1={1,2,3,0,0,0};
    vector<int> nums2={2,5,6};

    int m=3;
    int n=3;

    Solution s;
    s.merge(nums1,m,nums2,n);

    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<" ";
    }

    return 0;
}