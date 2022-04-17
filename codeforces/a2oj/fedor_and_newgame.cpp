#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m,k; cin>>n>>m>>k;

    vector<int> arr(m+1);

    for(int i=0; i<=m; i++) cin>>arr[i];

    int fedor = arr[m];

    int cnt = 0;
    for(int i=0; i<m; i++){
        int c = 0;
        for(int j=0; j<=n; j++){
            if((arr[i] & (1 << j)) != (fedor & (1 << j))) c++;
        }
        if(c <= k) cnt++;
    }

    cout<<cnt<<endl;
}