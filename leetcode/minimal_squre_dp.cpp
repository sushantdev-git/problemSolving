
#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int ans = 0;

        vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1,0));

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size();j++){
                
                if(matrix[i][j] == '1'){
                    dp[i+1][j+1] = 1 + min(dp[i][j+1], min(dp[i+1][j], dp[i][j]));
                    ans = max(ans, dp[i+1][j+1]);
                }
                else{
                    dp[i+1][j+1] = 0;
                }
            }
        }
        cout<<ans<<endl;
        return ans;
    }
};


int main(){

    Solution s;
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout<<s.maximalSquare(matrix)<<endl;
    return 0;
}