#include<bits/stdc++.h>
using namespace std;

//diretives
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


void solve(){
    int n;
    cin>>n;

    unordered_map<int,int> mp;
    for(int i=0; i<n-1; i++){
        int x; cin>>x;
        mp[x]++;
    }

    vector<int> A = {1};
    for(auto &p: mp){
        A.push_back(p.second);
    }

    sort(A.rbegin(), A.rend());

    queue<int> q;
    for(auto &i: A) q.push(i);

    int time = 0;
    n = q.size();
    while(n--){
        int x = q.front(); q.pop();
        if(x > 1) q.push(x-1);
        time++;
    }

    n = q.size();
    int extra = 0;
    while(n--){
        int x = q.front(); q.pop();
        
        x -= (time-1);
        if(x > 0){
            int sub = min(x, extra);
            x -= sub;
            extra -=sub;
        }


        if(x > 1){
            time += ceil(x/2.0);
            x %= 2;
        }

        if(x == 1) extra++;

    }

    cout<<time<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}