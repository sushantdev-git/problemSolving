#include<bits/stdc++.h>
using namespace std;

void print(int x){cout<<x<<endl;}


bool check(int a, int b){
    if(a%b == 0){
        cout<<"YES"<<endl;
        return true;
    }

    return false;
}

void solve(){

    int a,b,c,x,n,m;
    cin>>a>>b>>c;

    //a and c is in series
    x = a+c;

    if(x%2 == 0){
        n = max(x/2,b);
        m = min(x/2,b);
        if(x/2 > b  && check(n,m)) return;
    }

    // b and c is in series
    int d = c - b;
    int let_a = b - d;

    n = max(let_a,a);
    m = min(let_a, a);

    if(let_a >= a && check(n,m)) return;

    //a and b is in series

    d = b - a;
    int let_c = b+d;

    n = max(let_c, c);
    m = min(let_c, c);

    if(let_c >= c && check(n,m)) return ;
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