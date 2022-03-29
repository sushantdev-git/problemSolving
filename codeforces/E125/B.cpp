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

void solve(int n, int x, int B, int y, vector<int> &ans){
    if(n <= 0) return;
    int a = ans.back();
    while(n > 0 && a+x <= B) {
        a+=x;
        ans.push_back(a);
        n--;
    }
    if(n > 0){
        a-=y;
        n--;
        ans.push_back(a);
    }
    return solve(n,x,B,y, ans);
}

void solve(){
    int n,B,x,y;
    cin>>n>>B>>x>>y;
    vector<int> ans = {0};
    solve(n,x,B,y, ans);
    // for(auto &i: ans) cout<<i<<" ";
    // cout<<endl;
    cout<<accumulate(ans.begin(),ans.end(),0LL)<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}