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

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        pq.push(x);
    }

    while(pq.size() > 1 && n > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        if(abs(a-b) <= 1) pq.push(a+b);
        else {
            print("NO");
            return;
        }

        n--;
    }

    if(pq.size() && n == 1) print("YES");
    else print("NO");

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}