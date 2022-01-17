#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m, rb, cb , rd, cd;
        cin>>n>>m>>rb>>cb>>rd>>cd;

        int dr=1, dc=1;
        int count = 0;

        while(rb != rd && cb != cd){
            if(rb+dr < 1 || rb+dr > n)dr=0-dr;
            if(cb+dc < 1 || cb+dc > m) dc=0-dc;
            rb+=dr;
            cb+=dc;
            count++;
        }

        cout<<count<<endl;
    }
}