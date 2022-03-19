#include<bits/stdc++.h>
using namespace std;

//diretives
#define pb push_back
#define int long long
#define S second
#define F first

template <class X> void print(X &x) {cout<<x<<"\n";}
void print(int i) {cout<<i<<endl;}
template <class X> void input_1darr(vector<X> &arr, int n){
    for(int i=0; i<n; i++) cin>>arr[i];
}
template <class X> void input_2darr(vector<vector<X>> &arr, int n, int m){
    for(int i=0; i<n; i++) {for(int j=0; j<m; j++) cin>>arr[i][j];}
}


void solve(){
    int n, m;
    cin>>n>>m;

    vector<pair<int,pair<int,int>>> arr(m);

    for(int i=0; i<m; i++){
        cin>>arr[i].S.F;
        cin>>arr[i].F;
    }

    for(int i=0; i<m; i++){
        arr[i].S.S=i+1;
    }

    sort(arr.begin(), arr.end());

    int we =0;
    vector<pair<int,int>> coor;
    for(int i = 0; i<2*n; i++) {
        we+=arr[i].F;
        coor.push_back({arr[i].S.F, arr[i].S.S});
    }

    sort(coor.begin(), coor.end());

    cout<<we<<endl;
    for(int i=0; i<n; i++){
        cout<<coor[i].S<<" "<<coor[2*n-i-1].S<<endl;
    }
    cout<<endl;



}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}