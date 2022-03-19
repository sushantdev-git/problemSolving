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

bool placeExam(int exams, int k, int lastdate){
    int currdate = 1;
    while(exams--){
        currdate+=k;
        currdate++;
        if(currdate > lastdate) break;
    }
    // cout<<currdate<<endl;
    return currdate <= lastdate;
}
void solve(){
    int n,d;
    cin>>n>>d;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    int exams = n;

    int l=0, r=d, mid;

    while(l <= r){
        mid = l + (r - l)/2;
        if(placeExam(exams, mid, d)){
            l = mid+1;
        }
        else r = mid-1;
    }

    cout<<r<<endl;


}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}