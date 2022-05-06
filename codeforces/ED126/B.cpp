#include<bits/stdc++.h>
using namespace std;

//diretives
#define pb push_back
#define int long long
#define ss second
#define ff first

#define size 32769


int mod = 32768;


void solve(vector<int> &dp){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];


    for(auto no: arr){

        int ans = 20;

        for(int j=0; j<=15; j++){
            for(int k=0; k<=15; k++){
                if(((j + no) * (1 << k)) % mod  == 0){
                    ans = min(ans, j+k);
                }
            }
        }

        cout<<ans<<" ";
    }
    cout<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    vector<int> dp(size, -1);
    while(t--) solve(dp);

    return 0;
}