#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

bool haveMin(int n, map<int,int> &mp){

    for(int i=n-1; i>=0; i--){
        if(mp[i]) return true;
    }
    return false;
}

void solve(){
    string s;
    cin>>s;

    map<int,int> mp;
    for(auto &ch: s){
        mp[ch-'0']++;
    }

    map<int,int> mp2;

    for(auto &ch: s){
        mp[ch - '0']--;
        if(haveMin(ch-'0', mp)){
            // cout<<"increasing "<<ch<<endl;
            mp2[min(ch - '0' + 1, 9)]++;
        } 
        else mp2[ch - '0']++;
    }

    for(auto &p: mp){
        mp2[p.first] += p.second;
    }

    string ans="";

    for(auto &p: mp2){
        ans += string(p.second, p.first+'0');
    }

    cout<<ans<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}