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

    set<int> s;
    unordered_map<int,int> mp;
    vector<int> arr(n);

    for(auto &i: arr){
         cin>>i;
         mp[i]++;
         s.insert(i);
    }

    for(int i=0; i<n; i++){
        if(s.size() == n-i){
            cout<<i<<endl;
            return;
        }

        mp[arr[i]]--;
        if(mp[arr[i]] == 0){
            s.erase(arr[i]);
        }
    }

    cout<<n<<endl;
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