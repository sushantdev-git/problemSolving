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

    vector<int> A(n);
    vector<int> B(n);

    for(int i=0; i<n; i++) cin>>A[i];
    for(int i=0; i<n; i++) cin>>B[i];


    unordered_map<int,int> mp;

    int i =n-1, j = n-1;
    while(i >= 0 || j >= 0){

        int a = A[i];
        int b = j >= 0 ? B[j] : 0;

        if(a != b){
            if(j+1 >= n){
                cout<<"NO"<<endl;
                return;
            }
            if(b == B[j+1]){
                mp[b]++;
                j--;
            }
            else if(mp[a]) {
                mp[a]--;
                i--;
            }
            else {
                cout<<"NO"<<endl;
                return;
            }
        }
        else i--, j--;
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