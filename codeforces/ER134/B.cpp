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

vector<pair<int,int>> dir = {{0, 1} , {1, 0},{0, -1}, {-1, 0}};

void solve(){
    
    int n, m, sx, sy, d;
    cin>>n>>m>>sx>>sy>>d;


    vector<vector<int>> dis(n+1, vector<int> (m+1, INT_MAX));

    dis[1][1] = 0;
    priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;

    pq.push({0, 1, 1});

    while(pq.size()){
        array<int,3> tp = pq.top(); pq.pop();

        int x = tp[1], y = tp[2], currdis = tp[0];
        // cout<<currdis<<endl;
        if(x == n && y == m) {
            cout<<currdis<<endl;
            return;
        }

        for(auto &p: dir){
            int dx = p.first;
            int dy = p.second;

            if(isValid(x+dx, y+dy, n, m) && (abs(x + dx - sx) + abs(y + dy - sy) > d)){
                if(dis[x+dx][y+dy] > currdis + 1){
                    dis[x+dx][y+dy] = currdis + 1;
                    pq.push({currdis + 1, x+dx, y+dy});
                }
            }
        }
    }

    cout<<-1<<endl;

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