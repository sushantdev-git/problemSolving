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

    string ans;
    bool tw=true;
    while(n>1){
        if(tw) {
            ans.pb('2');
            n-=2;
        }
        else {
            ans.pb('1');
            n-=1;
        }
        tw = !tw;
        // cout<<n<<" "<<ans<<endl;
    }

    if(n == 1){
        ans.pb('1');
        int j = ans.size()-2;
        if(j > 0 && ans[j] == ans[j+1]){
            while(j > 0){
                swap(ans[j], ans[j-1]);
                j-=2;
            }
        }
    }
    // cout<<ans.size()<<endl;
    cout<<ans<<endl;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}