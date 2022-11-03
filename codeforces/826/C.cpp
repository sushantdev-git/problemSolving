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

void solve(){ 
    int n;
    cin>>n;
    vi arr(n);
    INP(arr, n);
 
    int currsum=arr[0];
    int mT=INT_MAX;
    for(int i=1;i<n;i++){
        
        int thickness=i, tempSum=0, count=0;
        for(int j=i;j<n;j++){
            tempSum+=arr[j];
            count++;
            if(tempSum==currsum){
                
                thickness=max(thickness, count);
                tempSum=0;
                count=0;
            }else if(tempSum>currsum){
                thickness=INT_MAX;
                break;
            }
        }
 
        if(tempSum!=0)
            thickness=INT_MAX;
        mT=min(mT, thickness);
        currsum+=arr[i];
    }
 
    if(mT==INT_MAX)
        mT=n;
 
    cout<<mT<<endl;
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