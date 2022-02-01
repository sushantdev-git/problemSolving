#include<bits/stdc++.h>
using namespace std;

void print(int x){cout<<x<<endl;}

template <class X> void print(X &x) {cout<<x<<endl;}


bool candefeat(long long ch, long long ca,long long mh,long long ma){
    long long x = (ch + ma -1)/ma;
    long long y =  (mh + ca -1)/ca;
    return x >= y;
}

void solve(){
    long long ch, ca, mh, ma, k ,w, a;
    cin>>ch>>ca>>mh>>ma>>k>>w>>a;

    for(int i=0; i<=k; i++){
        long long temp_ca = ca+ i*w;
        long long temp_ch = ch+ (k-i)*a;
        if(candefeat(temp_ch, temp_ca, mh, ma)){
            cout<<"YES"<<endl;
            return;
        }
    }
    
    cout<<"NO"<<endl;
    
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}