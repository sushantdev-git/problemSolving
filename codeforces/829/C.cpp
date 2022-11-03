#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first
#define all(arr) arr.begin(), arr.end()
#define rall(arr) arr.rbegin(), arr.rend()

#define INP(v, n) for(int i=0; i<n; i++) cin>>v[i];
#define OUT(v, n) for(int i=0; i<n; i++) cout<<v[i]<<" "; cout<<endl;

typedef vector<int> vi;

void solve(){
    int n; cin>>n;

    vi arr(n);
    INP(arr, n);

    vector<pair<int,int>> ans;

    int sum = 0;

    int i=0;
    while(i < n){
        if(sum == 0 && i+1 < n && arr[i] == arr[i+1]){
            ans.push_back({i, i+1});
            i+=2;
        }
        else{
            sum += arr[i];
            ans.push_back({i, i});
            i++;
        }
        // cout<<i<<" "<<sum<<endl;
    }

    if(sum == 0){
        cout<<ans.size()<<endl;
        for(auto &p: ans){
            cout<<p.first+1<<" "<<p.second+1<<endl;
        }
    }
    else cout<<-1<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}