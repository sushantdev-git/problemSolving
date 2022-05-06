#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    
    string s;
    cin>>s;

    int n = s.size();

    int lastone = 0, lastzero = n-1;

    int i = 0;
    while(i < n && (s[i] == '?' || s[i] == '1')){
        if(s[i] == '1') lastone = i;
        i++;
    }

    i = n-1;

    while(i >= 0 && ((s[i] == '?' || s[i] == '0'))){
        if(s[i] == '0') lastzero = i;
        i--;
    }

    cout<<(lastzero - lastone +1)<<endl;


}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}