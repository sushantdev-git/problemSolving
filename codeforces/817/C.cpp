#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n;
    cin>>n;

    unordered_map<string,int> mp;

    vector<vector<string>> words(3, vector<string>());

    for(int i=0; i<3; i++){
        for(int j=0; j<n; j++){
            string temp; cin>>temp;
            words[i].push_back(temp);
            mp[temp]++;
        }
    }

    vector<int> scores(3, 0);

    // for(auto &v: words){
    //     for(auto &word: v) cout<<word<<" ";
    //     cout<<endl;
    // }

    for(int i=0; i<3; i++){
        for(int j=0; j<n; j++){
            if(mp[words[i][j]] == 1) scores[i]+=3;
            else if(mp[words[i][j]] == 2) scores[i]+=1;
        }
    }

    for(auto &i: scores) cout<<i<<" ";
    cout<<endl;
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