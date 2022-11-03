#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n, q;
    cin>>n>>q;

    deque<pair<int,int>> dq;

    for(int i=1; i<=n; i++){
        int x; cin>>x;
        dq.push_back({i,x});
    }

    vector<int> res;
    int lastwin = 1;
    for(int i=1; i<=n; i++){
        pair<int,int> a = dq.front(); dq.pop_front();
        pair<int,int> b = dq.front(); dq.pop_front();

        int win = a.second > b.second ? a.first : b.first;
        lastwin = win;
        res.push_back(win);

        if(win == a.first) dq.push_front(a);
        else dq.push_back(a);

        if(win == b.first) dq.push_front(b);
        else dq.push_back(b);
    }

    // for(auto &i: res) cout<<i<<" ";
    // cout<<endl;

    for(int i=1; i<=q; i++){
        int p, k; cin>>p>>k;

        auto a = lower_bound(res.begin(), res.begin()+min(n, k), p);
        auto b = upper_bound(res.begin(), res.begin()+min(n, k), p);

        if(k <= n) cout<<b-a<<endl;
        else{
            if(p == lastwin) cout<<b-a + k - n<<endl;
            else cout<<b-a<<endl;
        }

    }

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