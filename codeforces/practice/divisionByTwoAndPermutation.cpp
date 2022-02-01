#include<bits/stdc++.h>
using namespace std;

template <class X> void print(X &x) {cout<<x<<endl;}

void solve(){
    int n;
    cin>>n;

    vector<int> arr(n);
    vector<bool> occupied(n+1, false);

    for(int i=0; i<n;i++)cin>>arr[i];



    for(int i=0; i<n; i++){
        if(arr[i] <= n && !occupied[arr[i]]){
            occupied[arr[i]] = true;
            continue;
        }

        while(arr[i] > n) arr[i]/=2; //bringing it to range.

        while(arr[i] > 1 && occupied[arr[i]]) arr[i]/=2;


        if(!occupied[arr[i]]) occupied[arr[i]] = true;
        else{
            print("NO");
            return;
        }
    }

    print("YES");


}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}