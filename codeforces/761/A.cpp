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
    string s, t;
    cin>>s>>t;

    vector<int> cnt(26,0);
    for(auto &c: s) cnt[c-'a']++;

    string ans;
    if(t == "abc" && cnt[0]){
        ans+= string(cnt[0],'a');
        ans+= string(cnt[2], 'c');
        ans+= string(cnt[1], 'b');

        for(int i=3; i<26; i++){
            ans+= string(cnt[i], 'a'+i);
        }
    }
    else{
        for(int i=0; i<26; i++){
            ans+= string(cnt[i], 'a'+i);
        }
    }

    cout<<ans<<endl;


}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}