#include<bits/stdc++.h>
using namespace std;

bool canSend(vector<int> &arr, int k, int d){

    int sum = 0;
    int i=0;
    for(i=0; i<arr.size(); i++){
        if(sum+arr[i]>k){
            sum = arr[i];
            d--;
        }
        else sum+=arr[i];

        if(d <= 0) break;
    }

    return i == arr.size();
}

int main(){

    int n,d;
    cin>>n>>d;

    long long left = 0;
    vector<int> arr(n);
    for(auto &i: arr) {
        cin>>i;
        left = max(left, (long long)i);
    }

    long long right = INT_MAX;
    long long ans = INT_MAX;
    while(left <= right){
        long long mid = left + (right -  left)/2;
        if(canSend(arr, mid, d)){
            // cout<<"do at "<<mid<<endl;
            right = mid-1;
            ans = min(ans, mid);
        }
        else left = mid+1;
    }
    cout<<ans<<endl;
}