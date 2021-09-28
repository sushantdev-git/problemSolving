#include<bits/stdc++.h>

using namespace std;
int n, m, k;
bool isValid(int i, int j){
    if(i >= 0 && i <n && j>=0 && j<m){
        return true;
    }
    return false;
}

bool traverse(vector<vector<int>> & mat, int x1, int y1, int x2, int y2, int &d){
    
    if(!isValid(x1,y1) || !isValid(x2,y2)){
        return false;
    }

    // cout<<"x1 "<<x1<<" y1 "<<y1<<" x2 "<<x2<<" y2 "<<y2<<" d "<<d<<endl;

    // cout<<(mat[x1][y1] == (0 || 1))<<" "<<(mat[x2][y2] == (0 || 1))<<endl;
    if((mat[x1][y1] == 0 ||mat[x1][y1] == 1) && (mat[x2][y2] == 0 || mat[x2][y2] ==  1)){
        d++;
        traverse(mat, x1-1, y1-1, x2-1, y2+1,d);
        if(d >= k){
            mat[x1][y1] = mat[x2][y2] = 1;
            // cout<<"x1 "<<x1<<" y1 "<<y1<<" x2 "<<x2<<" y2 "<<y2<<" d "<<d<<endl;
            // cout<<"set 1 "<<mat[x1][y1]<<" "<<mat[x2][y2]<<endl;
            return true;
        }
    }

    return false;
}

string validate(vector<vector<int>> & mat){

    for(int i=k; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 0){
                int d =0;
                // cout<<"start"<<i<<" "<<j<<endl;
                if(traverse(mat, i-1, j-1, i-1, j+1, d)){
                    mat[i][j] = 1;
                };
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 0){
                return "NO";
            }
        }
    }

    return "YES";
}

int main(){
    int t;
    cin>>t;

    while(t--){
        cin>>n>>m>>k;

        vector<vector<int>> mat(n, vector<int>(m));

        char c;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>c;
                mat[i][j] =  c == '*' ? 0 : -1;
            }
        }

       cout<<validate(mat)<<endl;

    }
}