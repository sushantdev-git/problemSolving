#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n, x, y;
    cin>>n>>x>>y;

    if(y < x) swap(x, y);

    if(x > 0 || y >= n || y==0){
        cout<<-1<<endl;
        return;
    }


    int win = 1;
    int cnt = y;

    vector<int> ans;
    for(int i=2; i<=n; i++){
        if(cnt) cnt--;
        else{
            win = i;
            cnt = y-1;
        }
        ans.push_back(win);
    }
    
    if(cnt) cout<<-1<<endl;
    else{
        for(auto &v: ans) cout<<v<<" ";
        cout<<endl;
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