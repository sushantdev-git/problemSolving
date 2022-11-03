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
    int n, q;
    cin>>n>>q;

    vi arr(n);
    INP(arr, n);

    int even = 0, odd = 0;
    int ec = 0, oc = 0;
    for(auto &i: arr){
        if(i&1) {
            odd+=i;
            oc++;
        }
        else {
            even+=i;
            ec++;
        }
    }

    for(int i=0; i<q; i++){
        int t, x;
        cin>>t>>x;

        if(t == 0){
            if(x&1){
                even+= ec*x;
                odd += even;
                oc += ec;
                even = 0;
                ec = 0;
            }
            else{
                even += ec*x;
            }
        }
        else{
            if(x&1){
                odd += oc*x;
                even += odd;
                ec += oc;
                odd = 0;
                oc = 0;
            }
            else{
                odd += oc*x;
            }
        }

        cout<<odd+even<<endl;
    }
    
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