#include <iostream>
using namespace std;
int fib(int n){
    if(n<=1){
        return n;
    }
    int curr=0;
    int prv1=1;
    int prv2=0;
    for(int i=2;i<=n;i++){
        curr=prv1+prv2;
        prv2=prv1;
        prv1=curr;
    }
    return curr;
}
int main(){
    int n;
    cin>>n;
    int result=fib(n);
    cout<<result<<endl;


    return 0;
}