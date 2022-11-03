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
 
    n-=4;
    int x;
    if(n%3==0)
        x=n/3-1;
    else{
        int l1=n/3;
        int l2=2*(n/3);
        if(n%3==2)
            l1++; l2++;
        x=min(abs(l1-1), abs(l2-1));
    }
    cout<<x<<endl;
}
 



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}