#include<bits/stdc++.h>
using namespace std;

int row, col, mod = 998244353;
bool isValid(int i, int j){
    if(i >=0 && i <row && j >=0 && j < col){
        return true;
    }
    return false;
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    //cout<<"res = "<<res<<endl;
    return res;
}

void bfs(int row, int col, vector<vector<bool>> visited, map<long int,long long> &mp){

    queue<pair<int,int>> q;
    q.push({row, col});
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int count = 0;
    int i=0;
    visited[row][col] = true;
    while(!q.empty()){
        long int n = q.size();
        mp[i]+=n%mod;
        while(n--){
            pair<int,int> lol = q.front();
            q.pop();

            int x = lol.first;
            int y = lol.second;

            for(int i=0; i<directions.size(); i++){
                pair<int,int>dir = directions[i];
                int tempx = dir.first+x;
                int tempy = dir.second+y;
                if(isValid(tempx,tempy) && !visited[tempx][tempy]){
                    q.push({tempx,tempy});
                    visited[tempx][tempy] = true;
                }
            }

        }
        //cout<<endl;
        i++;
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        
        cin>>row>>col;

        if(col < row){
            int temp = col;
            col = row;
            row = temp;
        }
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        map<long int,long long> mp;
        for(int i=0; i< row; i++){
            
            for(int j=0; j< col; j++){
                vector<vector<bool>> vistemp = vis;
                bfs(i, j, vistemp, mp);
                vis[i][j] = true;
            }

        }

        long long ans = 0;
        int lmao=1;
        int count = 0;
        for(auto i: mp){
            
            if(i.first == 0){
                continue;
            }
            cout<<i.first<<" "<<i.second<<endl;
            count+=i.second;
            ans = (ans + i.second*binpow(31,lmao-1,mod))%mod;
            lmao++;
        }
        cout<<ans<<endl;
        cout<<count<<endl;
        cout<<"---------------------------------"<<endl;
    }
    return 0;
}