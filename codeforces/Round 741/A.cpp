#include<bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin>>t;
    
    while(t--){
        int l,r;
        cin>>l>>r;

        if(r >= 2*l){
            cout<<(r-1)/2<<endl;
        }
        else{
            cout<<r -l<<endl;
        }
    }
}