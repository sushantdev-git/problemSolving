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
    
    int n, a, b; cin>>n>>a>>b; 
    vector<int> arr(n+1);
    arr[0] = 0;

    for(int i=1; i<= n; i++) cin>>arr[i];

    int curr = 0;

    for(int i=1; i<= n; i++){
        if(a <= b*i){
            curr = n-i;
            break;
        }
    }

    int sum = (a+b)*arr[curr];

    for(int i=curr+1; i<=n; i++){
        sum += (arr[i] - arr[curr])*b;
    }

    cout<<sum<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}