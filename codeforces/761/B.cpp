#include<stdio.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);

}

void solve(int n){
    int flag = 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int g = gcd(i,j);
            //cout<<i<<" "<<j<<" "<<g<<endl;
            if((n-g==i+j && g!=i)){
                cout<<i<<" "<<j<<" "<<g;
                flag = 1;
                break;
            }
        }
        if(flag==1)
            break;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        //cout<<gcd(6,9);
        solve(x);
    }

}