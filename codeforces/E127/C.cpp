#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

int cntDays (int cost, int money, int days, int costTillPrevProduct, int item){
    int lo = 0, hi = days;

    int ans = 0;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        //cost of current item on mid day is cost +mid
        //now before buying the current item we will have brought till previous item as item is sorted in ascending order
        //so we check if money is left to buy this item.
        //i.e (money - costTillPreviousItemOnCurrentDay)
        //by doing this we can find what is the max day we can buy this product
        //and then we add it to our total cnt
        if((money - (costTillPrevProduct + mid*(item-1))) >= (cost + mid)){
            ans = mid+1;
            lo = mid+1;
        }
        else hi = mid-1;
    }

    return ans;
}
void solve(){
    int n;
    cin>>n;
    int money;
    cin>>money;

    vector<int> arr(n);
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<int> prefix(n);
    prefix[0] = arr[0];

    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1]+arr[i];
    }

    int days = money - arr[0] + 1;

    int cnt = max(days, 0LL);
    for(int i=1; i<n; i++){
        //how many days I can buy the i'th item
        cnt += cntDays(arr[i],money,days,prefix[i-1], i+1);
    }


    cout<<cnt<<endl;

}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}   