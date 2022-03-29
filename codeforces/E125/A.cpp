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


bool isSquare(int no){
    for(int i=1; i<100; i++){
        if(i*i == no) return true;
    }
    return false;
}

void solve(){
    int x,y;
    cin>>x>>y;


    if(x == 0 && y == 0){
        print(0); return;
    }

    int ans = 2;
    
    int euc = x*x+y*y;
    if(isSquare(euc)) ans = 1;
    print(ans);

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}