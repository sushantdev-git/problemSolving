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

    vector<pair<char,int>> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i].ss;
    for(int i=0; i<n; i++) cin>>arr[i].ff;

    vector<int> red;
    vector<int> blue;

    for(int i=0; i<n; i++){
        if(arr[i].ff == 'R') red.push_back(arr[i].ss);
        if(arr[i].ff == 'B') blue.push_back(arr[i].ss);
    }

    sort(blue.begin(), blue.end());

    int curr = 1;
    for(int i=0; i<blue.size(); i++){
        if(blue[i] < curr){
            cout<<"NO"<<endl;
            return;
        }
        else {
            blue[i] = curr;
            curr++;
        }
    }

    sort(red.rbegin(), red.rend());

    curr = n;
    for(int i=0; i<red.size(); i++){
        if(red[i] > curr){
            cout<<"NO"<<endl;
            return;
        }
        else{
            red[i] = curr;
            curr--;
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