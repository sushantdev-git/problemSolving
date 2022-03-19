#include<bits/stdc++.h>
using namespace std;

//diretives
#define pb push_back
#define int long long
#define S second
#define F first

template <class X> void print(X &x) {cout<<x<<"\n";}
void print(int i) {cout<<i<<endl;}
template <class X> void input_1darr(vector<X> &arr, int n){
    for(int i=0; i<n; i++) cin>>arr[i];
}
template <class X> void input_2darr(vector<vector<X>> &arr, int n, int m){
    for(int i=0; i<n; i++) {for(int j=0; j<m; j++) cin>>arr[i][j];}
}


void solve(){
    string s;
    cin>>s;

    char c;
    cin>>c;

    for(int i=0; i<s.size(); i++){
        // cout<<s[i]<<" "<<i<<" "<<s.size()-1-i<<endl;
        if(s[i] == c && i%2 == 0 && (s.size()-1-i)%2 == 0){
            print("YES");
            return;
        }
    }

    print("NO");


}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}