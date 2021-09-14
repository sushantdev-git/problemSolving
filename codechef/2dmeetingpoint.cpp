#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int> xarr(n);
        vector<int> yarr(n);

        for(int i=0; i<n; i++){
            cin>>xarr[i];
        }

        for(int i=0; i<n; i++) {
            cin>>yarr[i];
        }

        int x = xarr[0];
        int y = yarr[0];

        for(int i=0; i<n; i++) {
            if(xarr[i] == yarr[i]){
                x = xarr[i];
                y = xarr[i];
            }
        }
        cout<<"-------------------"<<endl;
        cout<<x<<" "<<y<<endl;
        int count = 0;

        for(int i=0; i<n; i++) {
            if(xarr[i] == x && yarr[i] == y){
                continue;
            }
            else if(xarr[i] == yarr[i]){
                count++;
            }
            else if(xarr[i] != x && yarr[i] !=y){
                int tempx = x - xarr[i];
                int tempy = y - yarr[i];
                cout<<"diff"<<tempx<<" "<<tempy<<endl;
                if(tempx == tempy || tempx == -tempy){
                    cout<<"how true"<<endl;
                    count++;
                }
                else{
                    count+=2;
                }
            }
            else{
                count++;
            }
            cout<<count<<endl;

        }

        cout<<count<<endl;
        cout<<"-------------------"<<endl;
    }
}