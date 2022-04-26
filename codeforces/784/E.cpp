#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n;
    cin>>n;

    vector<string> arr(n);

    for(int i=0; i<n; i++) cin>>arr[i];

    vector<int> fir(26, 0);
    vector<int> sec(26, 0);

    map<string,int> mp;

    int ans = 0;
    for(int i=0; i<n; i++){
        string s = arr[i];

        int val = (fir[s[0] - 'a'] + sec[s[1] - 'a'] - 2*mp[s] );
        
        ans += val;
        fir[s[0] - 'a']++;
        sec[s[1] - 'a']++;
        mp[s]++;
        // cout<<s<<" "<<val<<" "<<ans<<endl;
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