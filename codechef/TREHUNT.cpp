#include<bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    cout<<"res = "<<res<<endl;
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){

        int row, col;
        cin>>row>>col;

        if(col < row){
            int temp = col;
            col = row;
            row = temp;
        }

        int maxdist = abs(row - 1)+abs(col - 1);
        int mod = 998244353;
        long long int ans = 0;
        int i;
        for(i=1; i<=maxdist; i++){
            int cal;

            if(i == 1) {
                cal = (col - i)*row + (row - i)*col;
            }
            else if(i == 2) {
                cal = (col - i)*row + (row - i)*col + ((col - (i-1))*2)*(row -1);
            }
            else if(i == 3) {
                cal = max(0,(col - i)*row) + max(0,(row - i)*col )+ max(0,((col - (i-1))*2)*(row -1)) + max(0,((row - (i-1))*2)*(col -1));
            }
            else if(i >= 4) {
                cal = max(0,(col - i)*row) + max(0,(row - i)*col) ;
                int colcross = max(0,((col - (i-1))*2)*(row -1));
                int rowcross = max(0,((row - (i-1))*2)*(col -1));
                if(rowcross == 0 && col/2 < row){
                    rowcross = max(0,(col - (i - row + 1))*2);
                }
                cal += rowcross+colcross;
            }
            ans = (ans+cal*binpow(31,i-1,mod))%mod;
            // cout<<i<<" "<<cal<<" ";
            // cout<<"ans "<<ans<<endl;
        }
        cout<<ans%mod<<endl;
        // cout<<"looprun "<<i<<" maxdist "<<maxdist<<endl;
    }
}