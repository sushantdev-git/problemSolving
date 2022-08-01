#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n,m;
    cin>>n>>m;

    // cout<<n<<" "<<m<<endl;

    vector<int> arr(n);
    for(auto &i: arr) cin>>i;

    string s = string(m, 'B');


    for(int i=0; i<n; i++){
        int x =  arr[i]-1;
        int mn = min(x, m-1-x);
        int mx = max(x, m-1-x);
        // cout<<i<<" "<<mn<<" "<<mx<<endl;
        if(s[mn] == 'B') s[mn] = 'A';
        else if(mx < m) s[mx] = 'A';
    }


    cout<<s<<endl;

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