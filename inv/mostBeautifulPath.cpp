#include<bits/stdc++.h>
using namespace std;

void print(int x){cout<<x<<endl;}

template <class X> void print(X &x) {cout<<x<<endl;}

string ans;
int maxfreq;

void cnt_max_freq(string &path){
    unordered_map<char, int> mp;
    int mx = INT_MIN;

    for(auto c: path){
        mp[c]++;
        mx = max(mx, mp[c]);
    }

    if(mx > maxfreq) {
        maxfreq = mx;
        ans = path;
    }
}

bool dfs(unordered_map<int, vector<int>> &edges, int node, vector<bool> &visited, string &path, string &s){
    if(visited[node]) return true;

    path.push_back(s[node-1]);

    visited[node] = true;
    for(auto i: edges[node]){
        if(dfs(edges, i, visited, path, s)) return true;
    }

    cnt_max_freq(path);
    path.pop_back();
    return false;
}


void solve(){
    int n, m;
    cin>>n>>m;
    string s;
    cin>>s;

    vector<int> x(m), y(m);

    for(int i=0; i<m; i++)cin>>x[i];
    for(int i=0; i<m; i++)cin>>y[i];

    unordered_map<int, vector<int>> edges;

    map<vector<unordered_map<char, int>>, int> mp;

    for(int i=0; i<m; i++){
        edges[x[i]].push_back(y[i]);
    }

    vector<bool> visited(n+1, false);

    for(int i=0; i<m; i++){
        string path="";
        if(!visited[x[i]]){
            dfs(edges, x[i], visited, path, s);
        }
    }


    cout<<ans<<endl;
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ans = "-1";
    maxfreq = INT_MIN;
    solve();

    return 0;
}