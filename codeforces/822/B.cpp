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
    
    int ans = 0;
    for(int i=1; i<= n; i++){
        vector<int> temp(i);
        temp[0] = 1;
        temp[i-1] = 1;
        for(auto &x: temp) cout<<x<<" ";
        cout<<endl;
    }
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