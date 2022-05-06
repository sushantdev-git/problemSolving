#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

class comp{
    public:
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        return a.first - a.second > b.first - b.second;
    }
};


void solve(){
    int n, money;
    cin>>n >> money;

    vector<int> A(n);
    vector<int> B(n);

    for(int i=0; i<n; i++) cin>>A[i];
    for(int i=0; i<n; i++) cin>>B[i];

    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;


    for(int i=0; i<n; i++){
        pq.push({A[i], B[i]});
    }


    int total = 0;
    while(pq.size()){

        pair<int,int> sweet = pq.top(); pq.pop();

        // cout<<sweet.first<<" "<<sweet.second<<endl;

        if(sweet.first <= money){
            int diff = sweet.first - sweet.second;
            int x = (money - sweet.first)/diff;
            x++;
            total += x;
            money -= diff*x;
        }
    }

    cout<<total<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}   