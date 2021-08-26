#include<bits/stdc++.h>
using namespace std;
#define lli long long int

lli mul(lli a, lli b, lli m){
    return (a*b)%m;
}
lli check(int n, int m){
    lli dp[n+1];
    dp[1] = 1;

    lli sum = 1;
    for(int i=2; i<=n; i++){
        dp[i] =sum;

        for(int j=1; j*j <=i ;j++){
            dp[i] = dp[i]+ mul(dp[j], (i/j - i/(j+1)),m);
            dp[i]%=m;

            if(j != i/j and j>1){
                dp[i] = dp[i]+dp[i/j];
                dp[i]%=m;
            }
        }

        sum = sum + dp[i];
        sum%=m;
    }

    return dp[n];

}

int main(){

    int n,m;
    cin>>n>>m;
    cout<<check(n,m)<<endl;
    return 0;
}