#include<bits/stdc++.h>
using namespace std;

#define int long long

//d = s*t
bool canSend(vector<int> &speed, int time, int people, int dis){
    int p = 0;

    for(auto &i: speed){
        int tempd = i*time;
        p += tempd/dis; //how many rounds the car can make, i.e that many no of person can ride
    }

    // cout<<time<<" "<<p<<endl;
    return p >= people;
}

int32_t main(){
    int n; cin>>n;
    vector<int> speed(n);

    for(auto &i: speed) cin>>i;

    int k, d; cin>>k>>d;

    int low = 0, high = INT_MAX;

    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(canSend(speed, mid, k, d)){
            ans = min(ans, mid);
            high = mid-1;
        }
        else low = mid+1;
    }

    cout<<ans<<endl;
}