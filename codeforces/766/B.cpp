#include<bits/stdc++.h>
using namespace std;

void print(int x){cout<<x<<endl;}
void print_inline(int x){cout<<x<<" ";}

void solve(){
    int n, m;
    cin>>n>>m;

    priority_queue<int, vector<int>,  greater<int>> pq;
    
    int xx;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            xx = max(i-0, n-1-i) + max(j-0, m-1-j);
            pq.push(xx);
        }
    }

    while(!pq.empty()){
        print_inline(pq.top());
        pq.pop();
    }

    cout<<endl;
}   




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}