#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

#define INP(v, n) for(int i=0; i<n; i++) cin>>v[i];
#define OUT(v, n) for(int i=0; i<n; i++) cout<<v[i]<<" "; cout<<endl;

typedef vector<int> vi;
typedef pair<int,int> pi;

int ans, n, m;

void dfs(int node, unordered_map<int,vector<pi>> &g, vector<int> &dis, int currdis){
    if(node == n){
        ans = min(ans, currdis);
        return;
    }

    // cout<<node<<" "<<currdis<<endl;

    for(auto &negh: g[node]){
        
        if(dis[negh.first] > dis[node] + negh.second){
            dis[negh.first] = dis[node] + negh.second;

            dfs(negh.first, g, dis, dis[negh.first]);

            for(auto &nNegh: g[negh.first]){

                if(dis[nNegh.first] > dis[node] + 2*negh.second){
                    dis[nNegh.first] = dis[node] + 2*negh.second;
                    dfs(nNegh.first, g, dis, dis[nNegh.first]);
                }
            }
        }
    }
}

void solve(){
    cin>>n>>m;

    ans = LLONG_MAX;
    unordered_map<int,vector<pi>> g;


    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;

        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }


    vector<int> dis(n, LLONG_MAX);
    dis[1] = 0;

    dfs(1, g, dis, 0);
    cout<<ans<<endl;
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