#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin>>s;

    int k; cin>>k;
    int n = s.size();
    k%=n;

    int l=0, r=k-1;

    while(l < r){
        swap(s[l], s[r]);
        l++, r--;
    }

    l = k, r = n-1;
    while(l < r){
        swap(s[l], s[r]);
        l++, r--;
    }

    l=0, r=n-1;
    while(l < r){
        swap(s[l], s[r]);
        l++, r--;
    }


    cout<<s<<endl;

}