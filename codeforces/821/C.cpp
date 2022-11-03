#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

void solve(){
    int n; cin>>n;

    vector<int> arr(n);
    for(auto &i: arr) cin>>i;

    map<int,set<int>> even, odd;

    for(int i=0; i<n; i++) {
        if(arr[i]%2 == 0) even[arr[i]].insert(i);
        else odd[arr[i]].insert(i);
    }

    vector<vector<int>> ans;

    int i=0, j = n-1;
    while(i < j){
        if(arr[i]%2 == 0){
            int mn = even.begin() -> first;
            if(mn < arr[i]){
                even[arr[i]].erase(i);
                if(even[arr[i]].size() == 0) even.erase(arr[i]);
                arr[i] = mn;
                auto idx = even[mn].begin();
                ans.push_back({i, *idx});

            }
        }
        else{
            int mn = odd.begin() -> first;
            if(mn < arr[i]){
                odd[arr[i]].erase(i);
                if(odd[arr[i]].size() == 0) odd.erase(arr[i]);
                arr[i] = mn;
                auto idx = even[mn].begin();
                ans.push_back({i, *idx});
            }
        }


        if(arr[j]%2 == 0){
            int mn = odd.rbegin() -> first;
            if(mn > arr[j]){
                even[arr[i]].erase(j);
                if(even[arr[j]].size() == 0) even.erase(arr[j]);
                arr[j] = mn;
                auto idx = odd[mn].b0egin();
                ans.push_back({j, *idx});
            }

        }
        else{
            int mn = even.begin() -> first;
            if(mn > arr[j]){
                odd[arr[j]].erase(j);
                if(odd[arr[j]].size() == 0) odd.erase(arr[j]);
                arr[j] = mn;
                auto idx = even[mn].begin();
                ans.push_back({j, *idx});
            }
        }

        i++; j--;
    }

    cout<<ans.size()<<endl;

    for(auto &v: ans){
        cout<<v[0]<<" "<<v[1]<<endl;
    }

    for(auto &i: arr) cout<<i<<" ";
    cout<<endl;
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