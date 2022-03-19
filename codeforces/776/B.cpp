#include<bits/stdc++.h>
using namespace std;

//diretives
#define pb push_back
#define int long long
#define S second
#define F first

template <class X> void print(X &x) {cout<<x<<"\n";}
void print(int i) {cout<<i<<endl;}
template <class X> void input_1darr(vector<X> &arr, int n){
    for(int i=0; i<n; i++) cin>>arr[i];
}
template <class X> void input_2darr(vector<vector<X>> &arr, int n, int m){
    for(int i=0; i<n; i++) {for(int j=0; j<m; j++) cin>>arr[i][j];}
}

int fx(int x, int a){
    return floor(x/a)+x%a;
}

void solve(){
    int l,r,a, ans;
    cin>>l>>r>>a;

    int la = r/a;
    la*=a;

    ans = fx(r, a);
    if(l < la && la <= r) ans = max(ans, fx(la-1, a));

    cout<<ans<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}