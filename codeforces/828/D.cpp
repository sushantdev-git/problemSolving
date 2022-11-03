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

// int minStep(vector<int> &arr, int sum, int last){

//     if(sum <= 0) return 0;

//     int ans = INT_MAX;
//     for(int i=arr.size()-1; i>=0; i--){
//         if(last != i){
//             ans = min(ans, 1+minStep(arr, sum-arr[i], i));
//         }
//     }

//     return ans;
// }

int solve(){
    int n;
    cin>>n;
 
    vi arr(n);
    INP(arr, n);
    int count=0;
    for(int i=0;i<n;i++){
        while(arr[i]%2==0){
            arr[i]/=2;
            count++;
        }
    }

    if(count>=n)
        cout<<"0 \n";
    else{        vi twos;
        for(int i=1;i<=n;i++){
            int num=i;
            int tempCount=0;
            while(num%2==0){
                num/=2;
                tempCount++;
            }
            twos.push_back(tempCount);
        }

        sort(twos.begin(), twos.end());

        int i=n-1;
        int moves=0;
        while(count<n && i>=0){
            count+=twos[i--];
            moves++;
        }

        if(count<n)
            cout<<"-1 \n";
        else
            cout<<moves<<endl;
    }
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