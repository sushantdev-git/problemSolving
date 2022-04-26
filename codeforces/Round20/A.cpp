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

    priority_queue<int> pq;

    for(int i=0; i<n; i++){
        int x; cin>>x;
        pq.push(x);
    }

    int chance = 0;

    while(pq.top() > 1){
        int x = pq.top();
        pq.pop();
        pq.push(x/2);
        pq.push(x - (x/2));
        chance = !chance;
    }

    if(chance == 1) cout<<"errorgorn"<<endl;
    else cout<<"maomao90"<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}