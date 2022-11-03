#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

bool isChild(int par, vector<int> child, int chd){
    // cout<<par<<" "<<chd<<endl;
    if(par == chd) return true;
    if(child[par] == -1) return false;
    return isChild(child[par], child, chd);
}

bool isParent(int chd, vector<int> child, int par){
    if(child[par] == par) return false;
    if(par == chd) return true;
    return isChild(child[par], child, par);
}


void setPar(int curr, set<int> &rem, vector<int> &child, vector<int> &parent){

    if(rem.size() == 0) return;
    if(parent[curr] != -1) return;
    int r = *rem.begin();
    rem.erase(r);
    

    if(!isChild(curr, child, r) || rem.size() == 0){
        child[r] = curr;
        parent[curr] = r;
        return;
    }
    setPar(curr, rem, child, parent);
    rem.insert(r);
}


void solve(){
    int n; cin>>n;
    string s;
    cin>>s;

    vector<int> par(26, -1), child(26, -1);

    set<int> rem;

    for(int i=0; i<26; i++) {
        // child[i] = i;
        rem.insert(i);
    }

    for(auto &ch: s){
        int no = ch - 'a';
        setPar(no, rem, child, par);
    }

    for(auto &ch: s){
        ch = 'a' + par[ch-'a'];
    }

    cout<<s<<endl;
    
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