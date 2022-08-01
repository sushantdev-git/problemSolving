#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

vector<int> query(int l, int r){
    cout<<"? l r"<<endl;
    vector<int> arr(r-l+1);
    for(auto &i: arr) cin>>i;
    return arr;
}


int solveRec(int l, int r){
    if(l >= r) return -1;

    vector<int> arr = query(l, r);
    int i = l, j = r;
    while(arr[i] <= l) i++;
    while(arr[j] >= r) j--;

    l = i, r = j;
    if(l == r) return l;

    int mid = l + (r - l)/2;

}

void solve(){
    int n;
    cin>>n;





}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    cout.flush();
    return 0;
}