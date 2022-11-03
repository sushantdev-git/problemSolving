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


    vector<pair<int,int>> arr(n);

    for(int i=1; i<=n; i++){
        cin>>arr[i-1].first;
        arr[i-1].second = i;
    }

    sort(arr.begin(), arr.end());

    cout<<arr[n-1].second<<endl;
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