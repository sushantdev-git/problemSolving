#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

bool comp(pair<int,int> &a, pair<int,int> &b){
    return a.first > b.first;
}

void solve(){
    int n,m;
    cin>>n>>m;

    int sum = 0;
    vector<pair<int,int>> arr(n);
    unordered_map<int,int> cry;
    for(int i=1; i<=n; i++){
        int x; cin>>x;
        arr[i-1] = {x, i};
        cry[i] = x;
        sum+=x;
    }

    unordered_map<int,vector<int>> negh;

    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        negh[x].push_back(y);
        negh[y].push_back(x);
    }


    sort(arr.begin(), arr.end(), comp);


    queue<pair<int,int>> q;
    for(auto &p: arr) {
        // cout<<p.first<<" "<<p.second<<" | ";
        q.push(p);
    }
    // cout<<endl;


    set<int> inMeet;

    int prevsize = 0;
    while(q.size()){
        int sz = q.size();

        if(prevsize == sz) break;
        prevsize = sz;

        while(sz--){
            pair<int,int> p = q.front(); q.pop();

            int cnt = 0;
            for(auto &n: negh[p.second]){
                if(inMeet.find(n) != inMeet.end()){
                    cnt++;
                }
            }

            if(cnt%2 == 0){
                // cout<<"inserting "<<p.second<<endl;
                inMeet.insert(p.second);
            }
            else q.push(p);
        }
    }

    int ims = 0;
    for(auto &x: inMeet){
        ims+=cry[x];
        // cout<<x<<" "<<cry[x]<<endl;
    }

    cout<<sum - ims<<endl;

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