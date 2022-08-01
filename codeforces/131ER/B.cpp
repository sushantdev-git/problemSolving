#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n;
    cin>>n;

    vector<int> ans;
    set<int> s;
    ans.push_back(1);
    for(int i=2; i<=n; i++){
        for(int j=i; j<=n; j*=2){
            if(s.find(j) != s.end()) break;
            else{
                ans.push_back(j);
                s.insert(j);
            }
        }
    }

    cout<<2<<endl;
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