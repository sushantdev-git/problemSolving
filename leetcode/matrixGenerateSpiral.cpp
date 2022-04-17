#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n, int  m) {
        int left = m-1, right = 0, top = 0, bottom = n-1;
        
        vector<vector<int>> mat(n, vector<int> (m));
        
        int val = 1;
        while(right <= left || top <= bottom){
            
            if(top <= bottom){
                for(int i=right; i<=left; i++) mat[top][i] = val++;
                top++;
            }
            if(right <= left){
                for(int i=top; i<= bottom; i++) mat[i][left] = val++;
                left--;
            }
            if(top <= bottom){
                for(int i=left; i>= right; i--) mat[bottom][i] =  val++;
                bottom--;   
            }
            if(right <= left){
                for(int i=bottom; i >= top; i--) mat[i][right] = val++;
                right++;
            }
            
        }
        
        return mat;
    }
};


int main(){
    Solution s;


    vector<vector<int>> mat = s.generateMatrix(5,5);

    for(auto &v: mat){
        for(auto &i: v) cout<<i<<"\t";
        cout<<endl;
    }

}