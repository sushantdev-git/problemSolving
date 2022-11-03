#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

bool valid(int x, int y, int n, int m){
    return x >= 0 && x < n && y >= 0 && y < m;
}


int dfs(int x, int y, vector<string> &mat, vector<vector<bool>> &visited){
    int n = mat.size(), m = mat[0].size();
    if(!valid(x,y,n,m)) return 0;
    if(mat[x][y] != '*') return 0;
    if(visited[x][y]) return 0;
    visited[x][y] = true;
    // cout<<x<<" "<<y<<endl;
    // cout<<mat[x][y]<<endl;

    vector<pair<int,int>> dir = {{0, 1}, {0, -1}, {1, 0}, {1, -1}, {1, 1}, {-1, 0}, {-1, 1}, {-1, -1}};

    int cnt = 1;
    for(auto &p: dir){
        int dx = p.first, dy = p.second;
        cnt += dfs(x+dx, y+dy, mat, visited);
    }   

    return cnt;
}

bool checkconfig(int x, int y, vector<string> &mat){
    vector<string> states = {"DL", "DR", "UL", "UR", "LD", "RD", "LU", "RU", "UX", "UZ", "DM", "DN"};
    unordered_map<char, pair<int,int>> mp;
    mp['D'] = {1, 0};
    mp['L'] = {0, -1};
    mp['R'] = {0, 1};
    mp['U'] = {-1, 0};
    mp['X'] = {1, -1};
    mp['Z'] = {1, 1};
    mp['M'] = {-1, -1};
    mp['U'] = {-1, 1};

    int n = mat.size(), m = mat[0].size();

    int cnt = 1;
    for(auto s: states){
        cnt = 1;
        int tx = x, ty = y;
        for(auto &ch: s){
            tx += mp[ch].first, ty += mp[ch].second;
            if(valid(tx, ty, n, m) && mat[tx][ty] == '*') cnt++;

        }
        if(cnt == 3) return true;
    }

    return false;
}


void solve(){
    int n,m; cin>>n>>m;

    vector<string> mat(n);
    for(auto &s: mat) cin>>s;

    vector<vector<bool>> visited(n, vector<bool> (m, false));

    // cout<<n<<" "<<m<<endl;
    // for(auto &s: mat){
    //     cout<<s<<endl;
    // }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && mat[i][j] == '*'){
                int cnt = dfs(i, j, mat, visited);
                // cout<<i<<" "<<j<<" "<<cnt<<endl;
                if(cnt != 3){
                    cout<<"NO"<<endl;
                    return;
                }
                if(!checkconfig(i, j, mat)){
                    cout<<"NO"<<endl;
                    return;
                }
                // cout<<endl;
            }
        }
    }

    cout<<"YES"<<endl;

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