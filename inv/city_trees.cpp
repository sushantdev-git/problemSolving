#include<bits/stdc++.h>
using namespace std;

int dfs(int node, set<int> &trees, vector<bool> &visited, unordered_map<int, vector<int>> &g){
    if(trees.find(node) == trees.end()) return 1;
    if(visited[node]) return 0;

    visited[node] = true;
    int ans = 0;

    for(auto &negh: g[node]){
        ans+=dfs(negh, trees, visited, g);
    }

    visited[node] = false;
    return ans;
}

int main(){

    int n, k;
    cin>>n>>k;

    unordered_map<int,vector<int>> g;
    for(int i=0; i<n-1; i++){
        int x, y;  cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    set<int> trees;

    for(int i=0; i<k; i++){
        int x; cin>>x;
        trees.insert(x);
    }

    vector<bool> visited(n, false);
    cout<<dfs(1, trees, visited, g)<<endl;

}