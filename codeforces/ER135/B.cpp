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
    for(int i=1; i<=n; i++) s.insert(i);

    vector<int> arr;

    int ans = 0;

    for(int i=1; i<=n; i++){
        int sum = i;
        vector<int> temp = {i};

        while(sum + 1 <= n){
            temp.push_back(sum+1);
            sum += sum + 1;
        }

        // cout<<i<<" "<<sum<<endl;
        if(sum >= ans) {
            ans = sum;
            arr = temp;
        }
    }

    // cout<<ans<<endl;
    for(auto &i: arr) {
        s.erase(i);
    }

    vector<int> rem(s.begin(), s.end());
    reverse(rem.begin(), rem.end());
    if(rem.size() %2 == 0) {
        for(auto &i: rem) cout<<i<<" ";
    }
    else{
        for(int i=0; i<rem.size()-3; i++) cout<<rem[i]<<" ";
        cout<<1<<" "<<2<<" "<<3<<" ";
    }
    for(auto &i: arr) cout<<i<<" ";
    cout<<endl;
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