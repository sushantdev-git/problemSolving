#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    
    string s;
    cin>>s;

    unordered_map<char,int> mp;

    for(auto &ch: s) mp[ch]++;

    int i=0, j = s.size()-1;

    while(i < j){

        if(mp[s[i]] = mp[s[j]]){
            mp[s[i]]--;
            mp[s[j]]--;
            i++;
            j--;
        }
        else if(mp[s[i]] < mp[s[j]]){
            mp[s[i]]--;
            i++;
        }
        else{
            mp[s[j]]--;
            j--;
        }

        for(auto &p1: mp){
            for(auto &p2: mp){
                if(abs(p1.second - p2.second) > 1){
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }

    cout<<"YES"<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}