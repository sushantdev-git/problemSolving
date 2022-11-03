

#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first


int sp(int node, unordered_map<int,vector<pair<int,int>>> &g, vector<int> &dis, vector<bool> &visited, vector<int> &fans){

    if(visited[node]) return INT_MAX;
    if(fans[node] != -1) return fans[node];
    visited[node] = true;
    int ans = dis[node];

    for(auto &negh: g[node]){
        ans = min(ans, negh.second + sp(negh.first, g, dis, visited, fans));
    }

    visited[node] = false;
    return fans[node] = ans;
}

void solve(){
    int n,m;

    cin>>n>>m;


    unordered_map<int,vector<pair<int,int>>> g;

    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;

        g[u].push_back({v,w});
    }


    vector<int> dis(n+1, INT_MAX);
    queue<pair<int,int>> q;
    dis[1] = 0;

    q.push({1, 0});

    while(q.size()){
        pair<int,int> node = q.front(); q.pop();

        for(auto &negh: g[node.first]){
            if(dis[negh.first] > node.second + negh.second){
                dis[negh.first] = node.second + negh.second;
                q.push({negh.first, dis[negh.first]});
            }
        }
    }

    vector<bool> visited(n+1, false);

    vector<int> ans(n+1,-1);

    for(int i=2; i<=n; i++){
        sp(i, g, dis, visited, ans);
    }

    for(int i=2; i<=n; i++){
        cout<<(ans[i] == INT_MAX ? -1 : ans[i])<<" ";
    }
    cout<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();

    return 0;
}