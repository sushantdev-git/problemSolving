#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,k; cin>>n>>k;

    vector<int> toSolve(k);
    for(auto &i: toSolve) cin>>i;

    unordered_map<int,vector<int>> g;

    for(int i=1; i<=n; i++){
        int x; cin>>x;
        for(int j=0; j<x; j++){
            int y; cin>>y;
            g[i].push_back(y);
        }
    }


    vector<bool> visited(n+1, false);
   
    queue<int> q;
    for(auto &i: toSolve) q.push(i);

    int slv = 0;

    while(q.size()){
        int node = q.front(); q.pop();
        visited[node] = true;
        for(auto &negh: g[node]){
            if(!visited[negh]){
                q.push(negh);
            }
        }

        slv++;
    }


    cout<<slv<<endl;
    
}