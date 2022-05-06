#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

bool haveSqrt(int n){
    int lo =1, hi = n;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(mid*mid == n) return true;
        else if(mid*mid < n) lo = mid+1;
        else hi = mid-1;
    }

    return false;
}


void solve(){
    int n;
    cin>>n;

    if(n == 1){
        cout<<0<<endl;
    }
    else if(n%2 != 0){
        cout<<1<<endl;
    }
    else{
        if(haveSqrt(n)) cout<<1<<endl;
        else cout<<-1<<endl;
    }
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}