#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

#define INP(v, n) for(int i=0; i<n; i++) cin>>v[i];
#define OUT(v, n) for(int i=0; i<n; i++) cout<<v[i]<<" "; cout<<endl;

typedef vector<int> vi;

/*
    In this question we are seeing a method to count no of subarray with given gcd value
    we are going to exploit a fact that max distinct value of gcd can be log2(max(A[i]));

    so for every A[i], we are going to check what was the differencet gcds till A[i-1]
    and with help of prev gcds we calculate what will be the curr gcds 

    So total time complexity of this will be O(nlogn)
    Codeforces problem : 475D - CGCDSSQ 
*/

void solve(){
    int n; cin>>n;

    vi arr(n);
    INP(arr, n);

    int q; cin>>q;

    vi que(q);
    INP(que, q);

    unordered_map<int,int> GCDSCount, GCDSTillPrev;

    for(int i=0; i<n; i++){
        unordered_map<int,int> GCDSTillCurr;

        GCDSTillPrev[arr[i]]++;

        for(auto &p: GCDSTillPrev){
            int gcd = p.first, cnt = p.second;
            GCDSTillCurr[__gcd(gcd, arr[i])] += cnt;
        }

        for(auto &p: GCDSTillCurr){
            GCDSCount[p.first] += p.second;
        }

        swap(GCDSTillPrev, GCDSTillCurr);
    }

    for(auto &i: que){
        cout<<GCDSCount[i]<<endl;
    }
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();

    return 0;
}