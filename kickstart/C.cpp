#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>


void solve(int tt){
    
    int n; cin>>n;
    vector<ll> arr(n);
    for(auto &i: arr) cin>>i;

    int l = 0, r = 0;
    int sum = 0, fsum = 0;

    while(r < n){
        cout<<r<<" "<<sum<<endl;
        if(sum + arr[r] >= 0) {
            sum += arr[r++];
            fsum += sum;
        }
        else{
            while(l < r && sum + arr[r] < 0) sum-=arr[l++];
            if(l == r){
                r++;
                l++;
            }
        }
    }

    sum-=arr[l++];

    while(l < r){
        if(sum >= 0) fsum += sum;
        sum -= arr[l++];
    }
    

    cout<<"Case #"<<tt<<": "<<fsum<<endl;
}

int main(){
    int t = 1;
    cin>>t;

    int tt = 1;
    while(t--){
        solve(tt);
        tt++;
    }
}