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


int mod = 998244353;

vector<int> fact(1001, -1);

int fac(int n){
    if(n <= 1) return 1;
    if(fact[n] != -1) return fact[n];
    return fact[n] = ((n%mod)*(fac(n-1)%mod))%mod;
}
void solve(){
    int n;
    cin>>n;

    if(n%2 != 0){
        cout<<0<<endl;
        return;
    }

    int a = fac(n/2);
    cout<<(a*a)%mod<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}