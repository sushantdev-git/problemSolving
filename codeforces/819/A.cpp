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

    vector<int> arr(n);

    for(auto &i: arr) cin>>i;

    int ans = arr[n-1] - arr[0];
    for(int i=1; i<n; i++) ans = max(ans, arr[i-1] - arr[i]);


    set<int> s;
    for(int i=1; i<n; i++) s.insert(arr[i]);

    if(s.size()) ans = max(ans, *s.rbegin() - arr[0]);

    s.erase(arr[n-1]);
    s.insert(arr[0]);

    ans = max(ans, arr[n-1] - *s.begin());

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