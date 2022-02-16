#include<bits/stdc++.h>
using namespace std;

template <class X> void print(X &x) {cout<<x<<endl;}
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
    string s;
    cin>>s;

    if(s.size() <3){
        cout<<0<<endl;
        return;
    }
    int c= 0;
    for(int i=0; i<=s.size()-3; i++){
        if(s[i] == s[i+1] && s[i+1] ==s[i+2] && s[i+2] == 'x') {
            c++;
        }
    }

    cout<<c<<endl;


}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}