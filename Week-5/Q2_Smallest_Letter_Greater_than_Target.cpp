#include <bits/stdc++.h>
using namespace std;
char nextGreatestLetter(vector<char>& letters, char target){
    int low=0;
    int high=letters.size()-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(letters[mid]>target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(ans==-1){
        return letters[0];
    }
    else{
        return letters[ans];
    }
}
int main(){
    int n;
    cin>>n;
    vector <char> letters(n);
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        letters[i]=c;
    }
    char target;
    cin>>target;
    char result=nextGreatestLetter(letters,target);
    cout<<result;
    



    return 0;
}