#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size()!=t.size()){
            return false;
        }

        int arr1[26]={};
        int arr2[26]={};

        for(char ch:s){
            int d=ch-'a';
            arr1[d]++;
        }

        for(char ch:t){
            int d=ch-'a';
            arr2[d]++;
        }

        int possible=1;

        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i]){
                possible=0;
                break;
            }
        }

        if(possible){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    string s="anagram";
    string t="nagaram";

    Solution obj;

    if(obj.isAnagram(s,t)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }

    return 0;
}