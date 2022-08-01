#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n, h, m;
    cin>>n>>h>>m;

    int t = h*60+m;

    vector<int> arr(n);

    for(auto &p: arr){
        int x,y;
        cin>>x>>y;
        p = x*60+y;
    }

    sort(arr.begin(), arr.end());

    for(auto &i: arr){
        if(i >= t){
            int sleep = i - t;
            cout<<sleep/60<<" "<<sleep%60<<endl;
            return;
        }
    }

    int sleep = 24*60 - t + arr[0];
    cout<<sleep/60<<" "<<sleep%60<<endl;

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