#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<int> dfs(unordered_map<int,vector<int>> connections, int node, int prev, vector<vector<int>> &ans, vector<bool> &todo, vector<bool> &done, int &c){
        if(todo[node]) return {node};
        if(done[node]) return {};
        
        todo[node] = true;
        c++;
        
        unordered_set<int> s;
        for(auto negh: connections[node]){
            if(negh != prev) s.merge(dfs(connections, negh, node, ans, todo, done,c));
        }
        
        s.erase(node);
        
        todo[node] = false;
        done[node] = true;
        if(s.size() == 0 && prev != -1) ans.push_back({prev, node});
        return s;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        vector<bool> todo(n, false);
        vector<bool> done(n, false);
        int c = 0;
        
        unordered_map<int,vector<int>> edges;
        for(auto v: connections){
            edges[v[0]].push_back(v[1]);
            edges[v[1]].push_back(v[0]);
        }
            
        dfs(edges, 0, -1, ans, todo, done, c);
        return ans;
    }
};

int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    cout<<s<<endl;
}