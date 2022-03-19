#include<bits/stdc++.h>
using namespace std;

//diretives
#define pb push_back
#define int long long
#define ss second
#define ff first

template <class X> void print(X &x) {cout<<x<<"\n";}
void print(int i) {cout<<i<<endl;}
template <class X> void input_1darr(vector<X> &arr, int n){
    for(int i=0; i<n; i++) cin>>arr[i];
}
template <class X> void input_2darr(vector<vector<X>> &arr, int n, int m){
    for(int i=0; i<n; i++) {for(int j=0; j<m; j++) cin>>arr[i][j];}
}


void solve(){
    int n;
    cin>>n;

    set<int> s;
    for(int i=1; i<=n; i++){
        s.insert(i);
    }

    vector<int> rem;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        if(s.find(a) != s.end()) s.erase(a);
        else {
            // cout<<a<<" ";
            rem.push_back(a);
        }
    }

    // cout<<endl;

    // cout<<s.size()<<" "<<rem.size()<<endl;
    sort(rem.rbegin(), rem.rend());

    for(int i=0; i<rem.size(); i++){
        auto it = s.end();
        it--;
        if(rem[i] >= (*it*2+1)){
            s.erase(it);
        }
        else break;
    }

    // cout<<s.size()<<endl;

    if(s.size() != 0) print(-1);
    else print((int)rem.size());
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}