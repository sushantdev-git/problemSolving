#include<bits/stdc++.h>
using namespace std;

void print(auto x){cout<<x<<endl;}

long long firstN(long long n){return (n*(n+1))/2;}

void solve(){

    int n;
    cin>>n;

    vector<int> h(n), k(n);
    
    for(int i=0; i<n; i++) cin>>k[i];
    for(int i=0; i<n; i++) cin>>h[i];

    vector<pair<int,int>> intervals;


    for(int i=0; i<n; i++){
        int r = k[i];
        int l = r - h[i] +1;
        intervals.push_back({l,r}); //creating intervals 
    }

    sort(intervals.begin(), intervals.end());

    int l=1, r =  0, cl, cr;
    long long ans = 0;
    for(auto &p: intervals){
        cl = p.first;
        cr = p.second;

        if(cl > r){
            ans+= firstN(r-l+1);
            r = cr;
            l = cl;
        }
        else{
            r = max(cr, r);
        }
    }

    ans += firstN(r-l+1);
    print(ans);

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}

/*
    1 2 3 4 5 6 7
    
*/