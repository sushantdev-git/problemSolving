#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;

    unordered_map<int,int> mp;

    int mx = 0;

    int ele = 0;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        // cout<<x<<" ";
        mp[x]++;
        if(mx < mp[x]){
            mx = mp[x];
            ele = x;
        }
    }
    // cout<<endl;

    int k; cin>>k;

    int rem = 0;

    for(auto &p: mp){
        if(p.first > ele){
            rem += p.second;
        }
    }

    mx+= min(k, rem);

    cout<<mx<<endl;


}