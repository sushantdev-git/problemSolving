#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    string s;
    cin>>s;

    int k; cin>>k;
    vector<int> arr(26,0);
    int mx = 0;
    for(int i=0; i<26; i++) {
        cin>>arr[i];
        mx = max(mx, arr[i]);
    }

    long long ans = 0;

    
    for(int i=0; i<s.size(); i++){
        ans += (i+1)*arr[s[i] - 'a'];
    }

    int i = s.size();
    while(k--){
        ans += (i+1)*mx;
        i++;
    }


    cout<<ans<<endl;


}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();

    return 0;
}