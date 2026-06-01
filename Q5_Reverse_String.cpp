#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
    }
};
int main(){
    vector<char> s={'h','e','l','l','o'};

    Solution obj;
    obj.reverseString(s);

    for(int i=0;i<s.size();i++){
        cout<<s[i]<<" ";
    }

    return 0;

}