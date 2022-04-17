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

    vector<int> a(n), b(n);

    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    int sum = 0;
    for(int i=1; i<n; i++){
        if((abs(a[i] - b[i-1]) + abs(b[i]- a[i-1])) <= (abs(a[i] - a[i-1]) + abs(b[i]- b[i-1]))){
            sum += (abs(a[i] - b[i-1]) +  abs(b[i]- a[i-1]));
            swap(a[i], b[i]);
        }
        else{
            sum += (abs(a[i] - a[i-1]) + abs(b[i]- b[i-1]));
        }
        
    }


    cout<<sum<<endl;


}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}