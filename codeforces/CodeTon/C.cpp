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
    int n;
    cin>>n;

    set<int> s;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        s.insert(x);
    }

    if(s.find(0) != s.end() && s.find(1) != s.end()){
        cout<<"NO"<<endl;
        return;
    }
    else if(s.find(1) == s.end()){
        cout<<"YES"<<endl;
        return;
    }

    for(auto &i: s){
        if(s.find(i-1) != s.end()){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}