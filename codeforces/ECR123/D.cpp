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

int mod = 998244353;

int binpowmod(int b, int p){
    long base = b;
    long res = 1;

    while(p){
        if(p%2 == 0){
            base=(base*base)%mod;
            p/=2;
        }
        else{
            res=(res*base)%mod;
            p--;
        }
    }
    return res;
}

void solve(){
    int n,m,k,q;
    cin>>n>>m>>k>>q;

    vector<pair<int,int>> queries;
    for(int i=0; i<q; i++){
        int a,b;
        cin>>a>>b;
        queries.push_back({a,b});
    }

    set<int> r,c;
    int cnt = 0;
    int ans = 1;
    for(int i=q-1; i>=0; i--){
        pair<int,int> que = queries[i];
        if(r.size()==n || c.size()==m)
            continue;
        if(r.find(que.first)!=r.end() && c.find(que.second)!=c.end())
            continue;
        ans = ans*1LL*k%mod;
        r.insert(que.first);
        c.insert(que.second);
    }

    cout<<ans<<endl;


}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}