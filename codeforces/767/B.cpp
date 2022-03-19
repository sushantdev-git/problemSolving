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
    int l,r,k;
    cin>>l>>r>>k;

    int odd;
    if(l == r && l == 1) {
        print("NO");
        return;
    }
    else if(l == r && l > 1) {
        print("YES");
        return;
    }

    if((r-l+1)%2 == 0) odd = (r-l+1)/2;
    else{
        if(l%2 == 0) odd = (r-l+1)/2;
        else odd = (r-l+1)/2+1;
    }

    if(odd <= k) print("YES");
    else print("NO");


}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}