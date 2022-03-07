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
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    vector<int> cnt(26,0);
    for(auto &c: s) cnt[c-'a']++;

    int pairs = 0, rem = 0;
    for(int i=0; i<26; i++){
        pairs+=cnt[i]/2;
        rem+=cnt[i]%2;
    }

    int ans = 0;
    if(pairs >= k){
        ans+= (pairs/k)*2; //dirstributing pairs in k strings, and as we are adding pairs into the strings, strings will be palindromes
        pairs%=k; //remaining pairs after distributing it in k strings;
    }

    rem+=(pairs)*2; //add remaining pairs in remaining element
    if(rem >= k) ans++; //if rem >= k we can add 1 more element to each string and it will still remain palindrome

    cout<<ans<<endl; 




}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}