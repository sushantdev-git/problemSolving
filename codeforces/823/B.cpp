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

    vector<pair<int,int>> pep;

    for(int i=0; i<n; i++){
        int x, t;
        cin>>x>>t;
        pep.push_back({x,t});
    }

    sort(pep.begin(),pep.end());

    vector<int> pref(n,0), suff(n,0);

    pref[0] = pep[0].first + pep[0].second;

    for(int i=1; i<n; i++){
        pref[i] = pref[i-1];
        pref[i] += pep[i].second;
        pref[i] += i*(pep[i].first - pep[i-1].first);
    }

    suff[n-1] = pep[n-1].first + pep[n-1].second;

    for(int i=n-2; i >= 0; i--){
        suff[i] = suff[i+1];
        suff[i] += pep[i].second;
        suff[i] += (n-1-i)*(pep[i+1].first - pep[i].first);
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