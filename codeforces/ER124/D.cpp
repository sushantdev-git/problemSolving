#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long
#define ss second
#define ff first

template <class X> void print(X &x) {cout<<x<<"\n";}
void print(int i) {cout<<i<<endl;}
template <class X> void input_1darr(vector<X> &arr, int n){
    for(int i=0; i<n; i++) cin>>arr[i];
}
template <class X> void input_2darr(vector<vector<X>> &arr, int n, int m){
    for(int i=0; i<n; i++) {for(int j=0; j<m; j++) cin>>arr[i][j];}
}


vector<pair<int,int>> direc = {{1,0}, {-1, 0}, {0,1}, {0, -1}};
int ulim = 1e6, llim = -1e6;

pair<int,int> dfs(pair<int,int> node, set<pair<int,int>> &s, map<pair<int,int>, pair<int,int>> &mp){

    if(node.ff > ulim || node.ff < llim || node.ss > ulim || node.ss < llim) return {ulim+1, ulim+1};
    if(mp.find(node) != mp.end()) return mp[node];

    // cout<<"negh search "<<node.ff<<" "<<node.ss<<endl;
    for(auto &dir: direc){
        int x = node.ff +dir.ff;
        int y = node.ss +dir.ss;
        // cout<<x<<" "<<y<<endl;
        if(s.find({x,y}) == s.end()){
            return mp[node] = {x,y};
        }
    }

    pair<int,int> mindis = {ulim+1, ulim+1};
    mp[node] = mindis;

    for(auto &dir: direc){
        int x = dir.ff + node.ff;
        int y = dir.ss + node.ss;
        pair<int,int> dis = dfs({x,y},s,mp);

        if(abs(dis.ff-node.ff)+abs(dis.ss-node.ss) < abs(mindis.ff-node.ff)+abs(mindis.ss-node.ss))
        {
            mindis = dis;
        }
    }
    
    return mp[node] = mindis;
}

void solve(){
    int n;
    cin>>n; 

    set<pair<int,int>> s;
    map<pair<int,int>, pair<int,int>> mp;
    vector<pair<int,int>> nodes;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        s.insert({a,b});
        nodes.pb({a,b});
    }


    for(auto &node: nodes){
        pair<int,int> mn = dfs(node,s, mp);
        // cout<<"ans ";
        cout<<mn.ff<<" "<<mn.ss<<endl;
    }


}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();

    return 0;
}