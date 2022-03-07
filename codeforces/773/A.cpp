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
    pair<int,int> a,b,c;
    cin>>a.first>>a.second;
    cin>>b.first>>b.second;
    cin>>c.first>>c.second;

    if(a.second == b.second && (c.second < a.second)){
        cout<<abs(b.first - a.first)<<endl;
        return;
    }
    if(a.second == c.second && ( b.second < a.second)){
        cout<<abs(c.first - a.first)<<endl;
        return;
    }
    if(b.second == c.second && (a.second < b.second)){
        cout<<abs(b.first - c.first)<<endl;
        return;
    }
    cout<<0<<endl;

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}