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
    int n, k;
    cin>>n>>k;


    string s;
    cin>>s;

    if(k < 1) cout<<1<<endl;
    else{
        n--;
        int i=0;
        bool ispa = true;
        while(i <= n){
            if(s[i] != s[n]){
                ispa = false;
                break;
            }
            i++;
            n--;
        }

        if(ispa) cout<<1<<endl;
        else cout<<2<<endl;
    }


}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}