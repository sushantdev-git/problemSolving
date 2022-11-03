#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

bool canSolve(unordered_map<int,vector<int>> &tree, int height, int k){

    queue<pair<int,int>> q;
    q.push({1, 0});

    // cout<<height<<endl;

    while(q.size()){
        pair<int,int> node = q.front(); q.pop();
        // cout<<node.first<<" "<<node.second<<" "<<k<<endl;
        if(node.second == height && node.second > 1){
            if(tree[node.first].size()){
                if(k){
                    q.push({node.first, 1});
                    k--;
                }
                else return false;
            }
        }
        else if(node.second > height){
            if(k){
                q.push({node.first, 1});
                k--;
            }
            else return false;
        }
        else{
            for(auto &child: tree[node.first]){
                q.push({child, node.second+1});
            }
        }
    }

    return q.size() == 0;
}

void solve(){
    int n, k;
    cin>>n>>k;

    
    unordered_map<int,vector<int>> tree;

    for(int i=2; i<=n; i++){
        int p; cin>>p;
        tree[p].push_back(i);
    }


    int lo = 0, hi = n;
    int ans = INT_MAX;

    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        // cout<<"main "<<lo<<" "<<hi<<" "<<mid<<endl;
        if(canSolve(tree, mid, k)){
            ans = min(ans, mid);
            hi = mid-1;
        }
        else lo = mid+1;
    }
    

    cout<<ans<<endl;
    
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