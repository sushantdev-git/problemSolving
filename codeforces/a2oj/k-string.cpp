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
    int k;
    cin>>k;
    string s;
    cin>>s;

    vector<int> mp(26,0);

    for(auto &c: s) mp[c-'a']++;

    string ans="";

    for(int i=0; i<26; i++){
        if(mp[i]%k != 0){
            print(-1);
            return;
        }
        ans+= string(mp[i]/k, 'a'+i);
    }


    string ans2="";
    while(k--) ans2.append(ans);
    print(ans2);
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();

    return 0;
}