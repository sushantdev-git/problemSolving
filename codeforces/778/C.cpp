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

    multiset<int> q;
    multiset<int> pq;

    int sum = 0;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        q.insert(x);
        sum += x;
    }

    pq.insert(sum);

    int size = 1;
    while(pq.size()){
        int x = *--pq.end(); //last element
        if(x < *--q.end()) break;

        pq.erase(--pq.end());

        if(q.find(x) != q.end()){
            q.erase(q.find(x));
        }
        else{
            pq.insert(x/2);
            pq.insert((x+1)/2);
        }
    }

    cout<<(q.empty() ? "YES" : "NO")<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}