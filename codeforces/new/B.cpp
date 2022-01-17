#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr){
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){

        int n; 
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];

        string stream;
        cin>>stream;

        int zerocnt = 0;
        for(auto c: stream) if(c == '0') zerocnt++;

        if(zerocnt == 0 || zerocnt == n/2){
            print(arr);
            continue;
        }

        if(zerocnt < n/2){
            int loop = n/2-zerocnt;
            for(int i=0; i<loop; i++) arr[i]++;
        }
        else{
            int loop = zerocnt - n/2;
            for(int i=0; i<loop; i++) arr[i]++;
        }


        print(arr);



    }
}