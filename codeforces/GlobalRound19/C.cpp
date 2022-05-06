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

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    queue<int> q;
    priority_queue<int> pq;


    int extra = 0, cnt = 0;
    for(int i=1; i<n-1; i++){
        if(arr[i]%2 == 0) pq.push(arr[i]);
        else q.push(arr[i]);

        while(q.size() && pq.size()){
            int top = pq.top(); pq.pop();
            int f = q.front(); q.pop();
            
            if(top - 2) pq.push(top -2);
            if(!extra){
                cnt++;
                extra++;
            }
            else extra--;

            pq.push(f+1);
        }
    }

    if(!q.size()){
        while(pq.size()) {
            cnt += pq.top()/2;
            pq.pop();
        }
    }

    cout<<(q.size() ? -1 : cnt)<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}