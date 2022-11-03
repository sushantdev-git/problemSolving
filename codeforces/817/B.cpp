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

    string a,b;
    cin>>a>>b;

    for(int i=0; i<n; i++){
        if(a[i] == b[i]) continue;
        else if((a[i] == 'G' && b[i] == 'B') || (b[i] == 'G' && a[i] == 'B')) continue;
        else {
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;

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