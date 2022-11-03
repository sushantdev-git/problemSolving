#include<bits/stdc++.h>
using namespace std;

//directives
#define int long long


int findMinPrice(vector<pair<int,vector<int>>> &books, int ind, unordered_map<int,int> &ownSkills, unordered_map<int,int> &reqSkills){

    if(ind >= books.size()){
        for(auto &sk: reqSkills){
            if(ownSkills[sk.first] < sk.second) return INT_MAX;
        }

        return 0;
    }


    int ans = INT_MAX;

    for(auto &sk: books[ind].second) ownSkills[sk]++;
    ans = min(ans, findMinPrice(books, ind+1, ownSkills, reqSkills) + books[ind].first);

    for(auto &sk: books[ind].second) ownSkills[sk]--;

    ans = min(ans, findMinPrice(books, ind+1, ownSkills, reqSkills));
}

void solve(){
    int n,m;
    cin>>n>>m;

    int k; cin>>k;
    unordered_map<int,int> reqSkills;

    for(int i=0; i<k; i++){
        int x; cin>>x;
        reqSkills[x]++;
    }

    unordered_map<int,int> ownSkills;
    int l; cin>>l;

    for(int i=0;i<l; i++){
        int x; cin>>x;
        ownSkills[x]++;
    }


    vector<pair<int,vector<int>>> books(m);
    for(auto &i: books) cin>>i.first;


    for(int i=0; i<m; i++){
        int x; cin>>x;
        for(int j=0; j<x; j++) {
            int s; cin>>s;
            books[i].second.push_back(s);
        }
    }

    


    int ans = findMinPrice(books, 0, ownSkills, reqSkills);

    if(ans == INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();

    return 0;
}