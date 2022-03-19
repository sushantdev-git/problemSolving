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
    int a,b,n;
    cin>>a>>b>>n;


    int x = 1;
    while(x--){
        int num = a;
        int j = 0;
        for(j=0; j<10; j++){
            if((num*10+j)%b==0) break;
        }
        if(j == 10) break;
        else a = num*10+j;
    }


    if(x == -1) {
        string ans = to_string(a);
        ans+=string(n-1,'0');
        print(ans);
    }
    else print(-1);

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();

    return 0;
}