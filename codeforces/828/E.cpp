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

unordered_map<int,int> getfac(int no){
    unordered_map<int,int> fac;

    int tno = no;
    for(int i=2; i*i <= tno && no; i++){
        while(no%i == 0){
            fac[i]++;
            no/=i;
        }
    }

    return fac;
}

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    int dddd = a*b;

    unordered_map<int,int> fac = getfac(dddd);

    // for(auto &p: fac){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }
    

    for(int i=a+1; i<=c; i++){
        unordered_map<int, int> cf = getfac(i);
        double no = 1;
        for(auto &p: fac){
            if(cf[p.first] < p.second){
                int diff = p.second - cf[p.first];
                no *= pow(p.first, diff);
            }
        }

        // cout<<no<<endl;

        if(no <= b){
            int q = b/no;
            no *= (q+1);
        }

        if(no <= d){
            cout<<i<<" "<<no<<endl;
            return;
        }
    }

    cout<<-1<<" "<<-1<<endl;
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