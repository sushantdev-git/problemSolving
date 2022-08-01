#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

bool check(int a, int b){
    if(a%10 == 0 && b%10 == 0) return a==b;
    if(a%10 == 0) return b+5 == a;
    if(b%10 == 0) return a+5 == b;
    if(a%10 == 5 || b%10 == 5) return a == b;

    while(a%10 != 2){
        a+=a%10;
    }

    while(b%10 != 2){
        b+=b%10;
    }

    int x = abs(a-b)/10;

    return x%2 == 0;
}

void solve(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(auto &i: arr) cin>>i;

    set<int> s1 = {0, 5};
    set<int> s2 = {1,2,3,4,6,8,7,9};

    bool sone = false, stwo = false;
    for(auto &i: arr){
        if(s1.find(i) != s1.end()) sone = true;
        if(s2.find(i) != s2.end()) stwo = true;

        if(sone && stwo){
            cout<<"No"<<endl;
            return;
        }
    }

    // cout<<"checking"<<endl;


    for(int i=1; i<n; i++){
        if(!check(arr[i-1], arr[i])){
            cout<<"No"<<endl;
            return;
        }
    }

    cout<<"Yes"<<endl;

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