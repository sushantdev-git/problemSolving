#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n,k;
    cin>>n>>k;

    priority_queue<int> pq;

    for(int i=1; i <= k; i++){
        int x; cin>>x;
        pq.push(x);
    }

    int cnt = 0;
    for(int i=k+1; i <= n; i++){
        int x; cin>>x;
        if(pq.top() > x){
            pq.pop();
            pq.push(x);
            cnt++;
        }
    }
    
    cout<<cnt<<endl;

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