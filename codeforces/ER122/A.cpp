#include<bits/stdc++.h>
using namespace std;

void print(int x){cout<<x<<endl;}

template <class X> void print(X &x) {cout<<x<<endl;}

void solve(unordered_map<int, vector<int>> &mp){
    int n;
    cin>>n;

    vector<int> check;

    if(n < 10) check = mp[10];
    else if(n < 100) check = mp[100];
    else check = mp[1000];

    int ans = -1, prevsame = 0;

    for(auto no: check){
        int same = 0;
        int xx = no, temp = n;
        while(temp > 0){
            if(xx%10 == temp %10) same++;
            xx/=10;
            temp/=10;
        }

        if(prevsame < same){
            prevsame = same;
            ans = no;
        }
    }

    cout<<ans<<endl;

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;

    unordered_map<int , vector<int>> mp;

    for(int i=7; i< 999; i+=7){
        if(i < 10) mp[10].push_back(i);
        else if(i < 100) mp[100].push_back(i);
        else mp[1000].push_back(i);
    }
    while(t--) solve(mp);

    return 0;
}