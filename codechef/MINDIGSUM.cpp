#include<bits/stdc++.h>
using namespace std;

long getMin(long n,long l, long r){

    if(r > n){
        return n;
    }
    if(n < l){
        return n;
    }

    long ans = INT_MAX;
    long base = 10;
    for(long i=l; i<=r; i++){

        long tempn = n;
        long sum = 0;
        while(tempn > 0){
            sum+=tempn%i;
            tempn = tempn/i;
        }
        if(sum < ans){
            ans = sum;
            base = i;
        }
        if(sum <=1){
            break;
        }
    }

    return base;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        long n,l,r;
        cin>>n>>l>>r;

        cout<<getMin(n,l,r)<<endl;
    }
}