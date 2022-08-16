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

    vector<int> arr(n);

    for(auto &i: arr) cin>>i;

    set<int> s;

    int cnt = 0;
    for(int i=1; i<n; i++){
        if(arr[i-1] > arr[i]){
            int j = i-1;
            while(j >= 0 && arr[j] != 0){
                if(s.find(arr[j]) == s.end()) cnt++;
                s.insert(arr[j]);
                arr[j] = 0;
                j--;
            }
        }

        if(s.find(arr[i]) != s.end()){
            int j = i-1;
            arr[i] = 0;
            while(j >= 0 && arr[j] != 0){
                if(s.find(arr[j]) == s.end()) cnt++;
                s.insert(arr[j]);
                arr[j] = 0;
                j--;
            }
        }
    }

    cout<<cnt<<endl;


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