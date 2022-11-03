#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){

    string s; cin>>s;
    int n = s.size();

    map<int, vector<int>> mp;

    for(int i=0; i<n; i++){
        mp[s[i]-'a'+1].push_back(i+1);
    }

    int start = s[0]-'a'+1, end = s[n-1]-'a'+1;
    if(s[0] > s[n-1]){
        start = s[n-1]-'a'+1;
        end = s[0]-'a'+1;

        for(auto &p: mp){
            reverse(p.second.begin(), p.second.end());
        }
    }

    // cout<<start<<" "<<end<<endl;

    vector<int> ans;

    while(start <= end && mp.lower_bound(start) != mp.end()){
        auto it = mp.lower_bound(start);
        if(it -> first <= end){
            for(auto &ind: it->second){
                ans.push_back(ind);
            }
        }
        // cout<<start<<" "<<it->first<<endl;
        start = it -> first;
        mp.erase(it);
    }

    if(s[0] > s[n-1]) reverse(ans.begin(), ans.end());
    cout<<abs(s[0] - s[n-1])<<" "<<ans.size()<<endl;
    for(auto &i: ans) cout<<i<<" ";
    cout<<endl;
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