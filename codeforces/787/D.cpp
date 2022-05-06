#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

vector<vector<int>> paths;
vector<int> currpath;

void dfs(int node, vector<vector<int>> &tree){

    currpath.push_back(node);
    bool fChild = false;
    for(auto &child: tree[node]){
        
        if(!fChild){
            dfs(child, tree);
            fChild = true;
        }   
        else{
            currpath = {};
            dfs(child, tree);
        }

    }

    if(!fChild) paths.push_back(currpath);
}

void solve(){
    int n;
    cin>>n;

    paths.clear();
    currpath.clear();

    vector<vector<int>> arr(n+1);

    int root = -1;
    for(int i=0; i<n; i++){
        int x; cin>>x;

        if(x == i+1) root = x;
        else arr[x].push_back(i+1);
    }


    dfs(root, arr);

    cout<<paths.size()<<endl;

    for(auto &v: paths){
        cout<<v.size()<<endl;
        for(auto &i: v) cout<<i<<" ";
        cout<<endl;
    }

    cout<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}