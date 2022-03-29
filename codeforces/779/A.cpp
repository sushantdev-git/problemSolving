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

    string s;
    cin>>s;

    string ans;
    ans.push_back(s[0]);

    int cnt = 0;
    for(int i=1; i<n; i++){
        int sz = ans.size();
        if(s[i] == '0' && ans[sz-1] == '0'){
            ans+="11";
            cnt+=2;
        }
        else if(s[i] == '0' && ans[sz-2] == '0'){
            ans+="1";
            cnt++;
        }
        ans+=s[i];
    }

    cout<<cnt<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}