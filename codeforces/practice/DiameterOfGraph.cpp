#include<bits/stdc++.h>
using namespace std;

template <class X> void print(X &x) {cout<<x<<endl;}
void print(int i) {cout<<i<<endl;}
template <class X> void input_1darr(vector<X> &arr, int n){
    for(int i=0; i<n; i++) cin>>arr[i];
}
template <class X> void input_2darr(vector<vector<X>> &arr, int n, int m){
    for(int i=0; i<n; i++) {for(int j=0; j<m; j++) cin>>arr[i][j];}
}

void solve(){
    long long n,e,k;
    cin>>n>>e>>k;

    if(e > n*(n-1)/2 || e < n-1) print("NO");
    else if(n == 1){
        if(k > 1) print("YES");
        else print("NO");
    }
    else if(e == n*(n-1)/2 && k > 2) print("YES");
    else if(k > 3) print("YES");
    else print("NO");

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}