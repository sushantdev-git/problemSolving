#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

#define INP(v, n) for(int i=0; i<n; i++) cin>>v[i];
#define OUT(v, n) for(int i=0; i<n; i++) cout<<v[i]<<" "; cout<<endl;

typedef vector<int> vi;

void solve(){
    
    int n; cin>>n;

    vi arr(n);
    INP(arr, n);

    sort(arr.begin(), arr.end());

    for(int i=1; i<n; i++){
        if(arr[i] == arr[i-1]){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
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