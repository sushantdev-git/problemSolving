#include<bits/stdc++.h>
using namespace std;

//diretives
#define pb push_back
#define int long long
#define ss second
#define ff first


void solve(){
    int n,k; cin>>n>>k;

    string s; cin>>s;

    vector<int> ans(n,0);

    int flip = 0;
    int tempk = k;
    for(int i=0; i < n-1 && k; i++){

        int currbit = flip & 1 ? !(s[i] - '0') : (s[i] - '0');
        //this is representing what is value of current bit after the flips done previously

        if(currbit && (k & 1)){
            //if currbit is 1 and k is odd then we know that if odd operations will be done in section [i+1...n]
            //then current bit value will become 0 so we use one operation
            ans[i] = 1;
            k--;
            flip++;
        }

        if(!currbit && !(k & 1)){
            //if currbit is 0 and k is even then we know that if even operations will be done in section [i+1...n]
            //then current bit value will become 0 so we use one operation
            ans[i] = 1;
            k--;
            flip++;
        }

    }

    ans[n-1] = k; //remaining operations will be done in last bit
    k = tempk;
    for(int i=0; i< n; i++){
        //ans[i] - representing how many time the remaining bits will flip
        //k parity representing if current bit will be flipped

        //now we check if we perform ans[i] -> how many operations the next sections will left with
        //if next section will be left with odd opertations the current bit going to flip else it will remain same.
        if((k - ans[i]) & 1){
            s[i] ^= '0'^'1';
            //0^0^1 = 1
            //1^0^1 = 0
        }
    }

    cout<<s<<endl;
    for(auto &i: ans) cout<<i<<" ";
    cout<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}