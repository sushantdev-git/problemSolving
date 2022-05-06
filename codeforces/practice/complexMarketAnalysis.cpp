#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void createPrimes(vector<bool> &primes){

    primes[0] = primes[1] = false;

    for(int i=2; i< 1000001; i++){
        if(primes[i]){
            for(int j=i*i; j < 1000001; j+=i) primes[j] = false;
        }
    }
}

void solve(vector<bool> &primes){
    int n,e;
    cin>>n>>e;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    vector<int> prefix(n,0);
    vector<int> suffix(n,0);

    for(int i=0; i<n; i++){
        if(arr[i] == 1){
            int val = i-e >= 0 ? prefix[i-e] : 0;
            prefix[i] += 1+val;
        }

        int j = n-1-i;
        if(arr[j] == 1){
            int val = j+e < n ? suffix[j+e] : 0;
            suffix[j] += 1+val;
        }
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        // cout<<arr[i]<<" "<<primes[arr[i]]<<endl;
        if(primes[arr[i]]){
            int x = i-e >= 0 ? prefix[i-e] : 0;
            int y = i+e < n ? suffix[i+e] :  0;

            ans += x+y;
            if(x != 0 && y != 0){
                ans += x*y;
            }
        }
    }

    cout<<ans<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;

    vector<bool> primes(1000001, true);
    createPrimes(primes);

    while(t--) solve(primes);

    return 0;
}