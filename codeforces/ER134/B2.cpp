#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

bool isValid(int x, int y, int n, int m){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

vector<pair<int,int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void solve(){
    
    int n, m, sx, sy, d;
    cin>>n>>m>>sx>>sy>>d;

    if(sy - d <= 1 && sx - d <= 1) cout<<-1<<endl;
    else if(sy + d >= m && sx + d >= n) cout<<-1<<endl;
    else if(sx - d <= 1 && sx + d >= n) cout<<-1<<endl;
    else if(sy - d <= 1 && sy + d >= m) cout<<-1<<endl;
    else cout<<n+m-2<<endl;

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