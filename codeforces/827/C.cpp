#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

#define INP(v, n) for(int i=0; i<n; i++) cin>>v[i];
#define OUT(v, n) for(int i=0; i<n; i++) cout<<v[i]<<" "; cout<<endl;

typedef vector<int> vi;

void solve(){
    
    vector<string> arr(8);

    for(int i=0; i<8; i++) cin>>arr[i];


    for(int i=0; i<8; i++){
        bool f = true;
        for(int j=0; j<8; j++){
            if(arr[i][j] != 'R') {
                f = false;
                break;
            }
        }

        if(f){
            cout<<"R"<<endl;
            return;
        }
    }

    cout<<"B"<<endl;
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