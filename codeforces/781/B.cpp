#include<bits/stdc++.h>
using namespace std;

//diretives
#define pb push_back
#define int long long
#define ss second
#define ff first

template <class X> void print(X &x) {cout<<x<<"\n";}
void print(int i) {cout<<i<<endl;}
template <class X> void input_1darr(vector<X> &arr, int n){
    for(int i=0; i<n; i++) cin>>arr[i];
}
template <class X> void input_2darr(vector<vector<X>> &arr, int n, int m){
    for(int i=0; i<n; i++) {for(int j=0; j<m; j++) cin>>arr[i][j];}
}


void solve(){
    int n;
    cin>>n;


    map<int,int> mp;
    int freq = 0;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        mp[x]++;
        freq = max(freq, mp[x]);
    }

    if(n == 1) cout<<0<<endl;
    else{
        int ans = 0;
        while(freq < n){
            ans++;
            int cnv = min(freq, n-freq);
            ans+=cnv;
            freq+=cnv;
        }

        cout<<ans<<endl;
    }

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}