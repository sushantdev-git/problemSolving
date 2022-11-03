#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n, m;
    cin>>n>>m;


    if(m%n == 0){
        cout<<"YES"<<endl;
        int x = m/n;
        while(n--) cout<<x<<" ";
        cout<<endl;
        return;
    }
    else if(m > n){
        if(n%2 == 1){ //odd places
            cout<<"YES"<<endl;
            int x = m - (n-1);
            while(n-- > 1) cout<<1<<" ";
            cout<<x<<endl;
            return;
        }
        
        if(n%2 == 0 && m%2 == 0){
            cout<<"YES"<<endl;
            int x = m - (n-2);
            while(n-- > 2) cout<<1<<" ";
            cout<<x/2<<" "<<x/2<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;

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