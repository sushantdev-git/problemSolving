#include<bits/stdc++.h>
using namespace std;

//directives
#define pb push_back
#define int long long
#define ss second
#define ff first

int trav1(vector<vector<int>> &arr, int n){
    int time = 0;
    bool down = true;
    int col = 0, row = 0;
    while(col < n){
        if(down){
            row = 1;
            if(arr[row][col] >= time){
                int diff = arr[row][col] - time + 1;
                time += diff;
            }
            else time++;
            down = false;
            // cout<<"moving down"<<endl;
            // cout<<col<<" "<<time<<endl;
        }
        else {
            row = 0;
            if(arr[row][col] >= time){
                int diff = arr[row][col] - time + 1;
                time += diff;
            }
            else time++;
            down = true;
            // cout<<"moving up"<<endl;
            // cout<<col<<" "<<time<<endl;
        }
        
        col++;
        if(col < n && arr[row][col] >= time){
            int diff = arr[row][col] - time + 1;
            time += diff;
        }
        else if(col < n) time++;
        // cout<<"moving right"<<endl;
        // cout<<col<<" "<<time<<endl;
    }

    // cout<<time<<endl;
    return time;
}

int trav2(vector<vector<int>> &arr, int n){
    int time = 0;
    for(int i=1; i<n; i++){
        if(arr[0][i] > time){
            int diff = arr[0][i] - time + 1;
            time += diff;
        }
        else time++;
    }

    for(int i=n-1; i>=0; i--){
        if(arr[1][i] > time){
            int diff = arr[1][i] - time + 1;
            time += diff;
        }
        else time++;
    }

    // cout<<time<<endl;
    return time;
}


int trav3(vector<vector<int>> &arr, int n){
    int time = 0;

    for(int i=0; i<n; i++){
        if(arr[1][i] > time){
            int diff = arr[0][i] - time + 1;
            time += diff;
        }
        else time++;
    }

    for(int i=n-1; i>0; i--){
        if(arr[0][i] > time){
            int diff = arr[1][i] - time + 1;
            time += diff;
        }
        else time++;
    }

    // cout<<t  ime<<endl;
    return time;
}


void solve(){
    int n;
    cin>>n;

    vector<vector<int>> mat(2, vector<int> (n));

    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++) cin>>mat[i][j];
    }


    cout<<min(trav1(mat, n), min(trav2(mat, n), trav3(mat,n)));
    cout<<endl;
    // cout<<endl;
    




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