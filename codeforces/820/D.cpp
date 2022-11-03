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

    vector<int> a(n), b(n);

    for(auto &i: a) cin>>i;
    for(auto &i: b) cin>>i;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        arr[i] = a[i] - b[i];
    }

    sort(arr.begin(), arr.end());

    

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