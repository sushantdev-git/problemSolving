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
char to_upper(char c) {
    return c < 'a' ? c : c - 32;
}
char to_lower(char c) {
    return c >= 'a' ? c : c + 32;
}

void solve(){
    int n;
    cin>>n;


    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++) cout<<j<<" ";
        for(int j=i; j>=1; j--) cout<<j<<" ";
        cout<<endl;
    }

    int i=1, j = n;
    while(i <= j){
        cout<<i<<" ";
        if(j > i) cout<<j<<" ";
        i++; j--;
    }
    cout<<endl;

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}