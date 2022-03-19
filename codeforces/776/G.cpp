#include<bits/stdc++.h>
using namespace std;

//diretives
#define pb push_back
#define int long long
#define S second
#define F first

template <class X> void print(X &x) {cout<<x<<"\n";}
void print(int i) {cout<<i<<endl;}
template <class X> void input_1darr(vector<X> &arr, int n){
    for(int i=0; i<n; i++) cin>>arr[i];
}
template <class X> void input_2darr(vector<vector<X>> &arr, int n, int m){
    for(int i=0; i<n; i++) {for(int j=0; j<m; j++) cin>>arr[i][j];}
}
int mod = 1e9+7;

int countShorutCuts(vector<vector<int>> g, int s, int t, int n){
    vector<int> dis(n+1, INT_MAX);
    int res = 0, mindis = INT_MAX;
    dis[s] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, s});

    while(!pq.empty()){
        pair<int,int> node = pq.top(); pq.pop();

        for(auto negh: g[node.S]){
            if(dis[negh] >= node.F + 1){
                pq.push({node.F+1, negh});
                dis[negh] = node.F+1;
            }

            if(negh == t){
                if(mindis == INT_MAX){
                    mindis = node.F+1;
                    res++;
                }
                else if(node.F == mindis) {
                    res++;
                    res%=mod;
                }
            }
            
        }   
    }

    return res;
}

void solve(){
    int n, m;
    cin>>n>>m;

    int s,t;
    cin>>s>>t;
    vector<vector<int>> g(n+1);

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout<<countShorutCuts(g, s, t, n)<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}