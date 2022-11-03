#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

typedef pair<int,int> pi;

vector<vector<char>> mat;

vector<pi> dir = {{0, 1}, {0, -1}, {1, 0}, {-1,0}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};

int calMax(int qx, int qy){

    // cout<<qx<<" "<<qy<<endl;

    queue<array<int,4>> q;

    for(auto &d: dir){
        int dx = d.first;
        int dy = d.second;

        q.push({qx, qy, dx, dy});
    }

    int ans = 0;

    while(q.size()){
        array<int,4> ff = q.front(); q.pop();
        int x = ff[0], y = ff[1];
        if(x < 0 || x >= 8 || y < 0 || y >= 8) continue;

        if(mat[x][y] == 'E'){
            mat[x][y] = 'O';
            ans = max(ans, 1+calMax(x, y));
            mat[x][y] = 'E';
        }

        ff[0] += ff[2];
        ff[1] += ff[3];

        q.push(ff);
    }

    return ans;

}

int main() {
    
    
    
    int qx, qy;

    mat.resize(8, vector<char> (8));

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            char c; cin>>c;
            mat[i][j] = c;
            if(c == 'Q'){
                qx = i, qy = j;
            }
        }
    }

    int ans = calMax(qx, qy);
    cout<<ans<<endl;

    return 0;
}