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

    sort(arr.begin(), arr.end());

    int ans = INT_MAX;

    for(int i=2; i<n; i++){
        int a = arr[i-2], b = arr[i-1], c = arr[i];
        int x1 = abs(a - b) + abs(a - c);
        int x2 = abs(b - a) + abs(b - c);
        int x3 = abs(c - a) + abs(c - b);

        ans = min(ans, min(x1, min(x1, x2)));
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