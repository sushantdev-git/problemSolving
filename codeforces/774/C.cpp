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

vector<long long> fac;

long long maxS = 1e12;
void generateFac(){

    long long fc=1;
    for(int i=2; fc<maxS; i++){
        fac.push_back(fc);
        fc*=i;
    }
}


void solve(){
    long long n;
    cin>>n;
    int ans = INT_MAX;
    for(int mask=0; mask <= (1 << 15); mask++){
        long long sum = 0;
        for(int i=0; i< 14; i++){
            if(mask & (1 << i)) sum+=fac[i];
        }

        int no_of_fac = __builtin_popcount(mask);
        if(sum <= n){
            ans = min(ans, __builtin_popcountll(n-sum)+no_of_fac);
        }
    }

    cout<<ans<<endl;

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    generateFac();
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}