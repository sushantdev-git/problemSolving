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

    vector<int> a(n), b(n);

    for(auto &i: a) cin>>i;
    for(auto &i: b) cin>>i;

    vector<int> min_ans, mx_ans(n);

    for(auto &i: a){
        auto it = lower_bound(b.begin(), b.end(), i);
        min_ans.push_back(*it-i);
    }

    int b1 = n-1, b2 = n-1; int cnt = 0;
    for(int i=n-1; i>=0; i--){
        cnt++;
        while(b1 >= 0 && b[b1] >= a[i]) b1--;
        mx_ans[i]=b[b2] - a[i];
        if(b2 - b1 == cnt){
            b2 = b1;
            cnt = 0;
        }
    }

    for(auto &i: min_ans) cout<<i<<" ";
    cout<<endl;
    for(auto &i: mx_ans) cout<<i<<" ";
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