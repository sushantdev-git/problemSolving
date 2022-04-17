#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    int mx = 0, mxi, mn = INT_MAX, mni;

    for(int i=0; i<n; i++){
        if(arr[i] > mx){
            mx = arr[i];
            mxi = i;
        }
        if(arr[i] <= mn){
            mn = arr[i];
            mni = i;
        }
    }

    
    if(mni == mxi) cout<<0<<endl;   
    if(mni < mxi) cout<<((n - (mni+2)) + mxi)<<endl;
    else cout<<(mxi + (n - mni -1))<<endl;
}