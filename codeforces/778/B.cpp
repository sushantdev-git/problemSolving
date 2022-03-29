#include<bits/stdc++.h>
using namespace std;

//diretives
#define pb push_back
// #define int long long
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
    string s;
    cin>>s;

    int n = s.size();
    vector<int> cnt(26,0);
    for(auto &ch: s) cnt[ch-'a']++;

    int i=0;
    while(i < n){
        cnt[s[i] - 'a']--;
        if(cnt[s[i] - 'a'] <= 0) break;
        i++;
    }

    cout<<s.substr(i,s.size())<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}