#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long reverse(int n){
        long long rev_num=0;

        while(n>0){
            rev_num=rev_num*10+n%10;
            n=n/10;
        }

        return rev_num;
    }

    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }

        return reverse(x)==x;
    }
};

int main(){
    int x=121;

    Solution obj;

    if(obj.isPalindrome(x)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }

    return 0;
}