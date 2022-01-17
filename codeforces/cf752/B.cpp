#include<bits/stdc++.h>
using namespace std;

int findMaxLengthPair(vector<int> &arr){

    int n = arr.size();
    unordered_map<int,int> mp;

    int ans = -1;
    for(int i=0; i<n; i++){
        if(mp.find(arr[i]) != mp.end()){
            ans = max(ans, mp[arr[i]]+(n - i));
        }
        mp[arr[i]] = i;
    }

    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0; i<n; i++)cin>>arr[i];

        cout<<findMaxLengthPair(arr)<<endl;

    }

    return 0;
}