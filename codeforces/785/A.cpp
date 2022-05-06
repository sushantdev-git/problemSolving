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

    int sum = 0;
    int n = s.size();

    for(int i=0; i<n; i++){
        sum += s[i] - 'a' +1;
    }

    if(s.size()%2 == 0){
        cout<<"Alice"<<" "<<sum<<endl;
    }
    else{
        
        int x = max(sum - (s[0] - 'a' +1 ) , sum - (s[n-1] - 'a' +1 ));
        int y = sum - x;

        // cout<<sum<<" "<<x<<" "<<y<<endl;
        if(x > y){
            cout<<"Alice "<<x - y<<endl;
        }
        else cout<<"Bob "<<y - x<<endl;
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