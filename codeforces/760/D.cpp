#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first


void solve(){
    int n, k;
    cin>>n>>k;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    sort(arr.begin(), arr.end());

    int score = 0;
    for(int i=0; i<n-2*k; i++){
        score += arr[i];
    }

    for(int i=n-2*k; i<n-k; i++){
        score += arr[i]/arr[i+k];
    }

    cout<<score<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}