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

    string s; cin>>s;

    int r = 0, b = 0;

    if(n == 1 && s[0] != 'W'){
        cout<<"NO"<<endl;
        return;
    }
    else if(n == 2){
        int cnt = 0;
        cnt += s[0] == 'W';
        cnt += s[1] == 'W';

        if(cnt % 2 != 0){
            cout<<"NO"<<endl;
            return;
        }
    }

    s.push_back('W');
    n++;
    
    int i=0;
    if(s[0]== 'W') i++;

    for(; i<n; i++){
        if(s[i] == 'R') r++;
        else if(s[i] == 'B') b++;
        else{
            if(r == 0 && b == 0) r=0, b=0;
            else if(!r || !b){
                cout<<"NO"<<endl;
                return;
            }
            else r=0, b=0;
        }

    }

    cout<<"YES"<<endl;


}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}