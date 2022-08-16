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

    int x = 0;
    int c = n/3;
    x = c*3;



    if(n-x == 1) {
        if(c > 0) c++;
        else c+=2;
    }
    else if(n-x == 2) c++;

    cout<<c<<endl;  


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