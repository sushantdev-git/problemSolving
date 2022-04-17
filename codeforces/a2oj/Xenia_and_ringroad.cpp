#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin>>n>>k;

    vector<int> arr(k);
    for(int i=0; i<k; i++) cin>>arr[i];

    int h = 1;
    long long cnt = 0;
    for(int i=0; i<k; i++){
        if(arr[i] >= h ) {
            cnt += arr[i] - h;
            h = arr[i];
        }
        else{
            cnt += (n - h + arr[i]);
            h = arr[i];
        }
    }

    cout<<cnt<<endl;
}