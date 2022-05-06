#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void dfs(int n, vector<unordered_map<int,int>> &edges, vector<bool> &visited, int prevw){
    if(visited[n]) return;

    visited[n] = true;
    // cout<<n<<" "<<prevw<<endl;

    for(auto negh: edges[n]){
        if(visited[negh.first]) continue;
        int w = 2;
        if(prevw == 3) {
            // cout<<negh.first<<" setting weight as "<<2<<endl;
            edges[n][negh.first] = 2;
            edges[negh.first][n] = 2;
            w = 2;
        }
        else {
            // cout<<negh.first<<" setting weight as "<<3<<endl;

            edges[n][negh.first] = 3;
            edges[negh.first][n] = 3;
            w = 3;
        }
        dfs(negh.first, edges, visited, w);
        prevw = w;
    }
    
}


void solve(){
    int n;
    cin>>n;

    vector<unordered_map<int,int>> edges(n+1);
    vector<int> in(n+1), out(n+1);
    
    queue<pair<int,int>> q;

    bool threeedge = false;
    for(int i=1; i<n; i++){
        int x,y; cin>>x>>y;
        edges[x][y] = 0;
        edges[y][x] = 0;
        // cout<<x<<" "<<edge[x].first<<" "<<edge[x].second<<endl;
        q.push({x,y});
        out[x]++;
        in[y]++;

        // cout<<x<<" "<<y<<" "<<out[x]<<" "<<in[y]<<endl;
        if(in[x] + out[x] > 2) threeedge = true;
        if(in[y] + out[y] > 2) threeedge = true;
    }

    if(threeedge){
        cout<<-1<<endl;
        return;
    }
    


    vector<bool> visited(n+1, false);


    for(int i=1; i<=n; i++){
        if(!visited[i]) dfs(i, edges, visited, 2);
    }


    // for(int i=1; i<=n; i++){
    //     cout<<i<<" "<<endl;
    //     for(auto &p: edges[i]){
    //         cout<<p.first<<" "<<p.second<<endl;
    //     }
    // }

    // cout<<endl;

    while(q.size()){
        pair<int,int> p = q.front(); q.pop();
        // cout<<p.first<<" "<<p.second<<" ";
        cout<<edges[p.first][p.second]<<" ";
    }

    cout<<endl;


}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}