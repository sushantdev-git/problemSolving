#include<bits/stdc++.h>
using namespace std;

bool checkSum(vector<vector<long long>> &prefsum, int sz, int maxsum){
    int sum = 0;
    int n = prefsum.size();
    for(int i=sz; i < n; i++){
        for(int j=sz; j < n; j++){
            int subGridSum = prefsum[i][j] - prefsum[i-sz][j] - prefsum[i][j-sz] + prefsum[i-sz][j-sz];
            sum = max(sum, subGridSum);
        }
    }
    return sum <= maxsum;
}

int findSize(vector<vector<int>> &mat, int maxsum){
    int n = mat.size();

    int ans = 0;
    int low = 1, high = n;

    vector<vector<long long>> prefsum(n+1, vector<long long>(n+1, 0));

    for(int i=1; i <=n; i++){
        for(int j=1; j<=n; j++){
            prefsum[i][j] = mat[i-1][j-1] + prefsum[i-1][j] + prefsum[i][j-1] - prefsum[i-1][j-1];
        }
    }

    while(low <= high){
        int mid = low + (high - low)/2;
        if(checkSum(prefsum, mid, maxsum)){
            low = mid+1;
            ans = max(ans, mid);
        }
        else high = mid-1;
    }

    return ans;
}


int main(){
    int n,m; 
    cin>>n>>m;

    vector<vector<int>> mat(n, vector<int> (m));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
        }
    }

    int maxsum;
    cin>>maxsum;

    cout<<findSize(mat, maxsum)<<endl;
}