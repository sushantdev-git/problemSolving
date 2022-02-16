#include<bits/stdc++.h>
using namespace std;

void print(int x){cout<<x<<endl;}

template <class X> void print(X &x) {cout<<x<<endl;}

void input_1darr(vector<int> &arr, int n){
    for(int i=0; i<n; i++) cin>>arr[i];
}

void solve(){
    int n, time;
    cin>>n>>time;

    string s;
    cin>>s;

    for(int i=0; i < min(n, time) ; i++){
        for(int i=1; i<s.size(); i++){
            if(s[i] == 'G' && s[i-1] == 'B'){
                swap(s[i], s[i-1]);
                i++;
            }
        }
    }

    print(s);


}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}