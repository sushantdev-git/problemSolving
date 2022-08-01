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
    for(int i=0; i<n; i++) arr[i] = i+1;

    for(int i=(n%2==0 ? 0 : 1); i<n; i+=2){
        if(i+1<n) swap(arr[i], arr[i+1]);
    }

    for(auto &i: arr) cout<<i<<" ";
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