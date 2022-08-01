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

    vector<int> arr(n);
    for(auto &i: arr) cin>>i;

    unordered_set<int> s(arr.begin(), arr.end());
    if(s.size() > 3){
        cout<<"NO"<<endl;
        return;
    }

    if(s.find(0) == s.end()){
        cout<<"NO"<<endl;
        return;
    }

    for(int i=2; i<n; i++){
        if(arr[i] != -arr[i-2]){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
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