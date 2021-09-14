
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        if(i>=0 && i<n && j>=0 && j<m){
            return true;
        }
        return false;
    }
    
    int bfs(queue<pair<int,int>> q, vector<vector<char>>&matrix){
        int size = 1;
        int elements = 3;
        vector<pair<int,int>> directions = {{0,1}, {1,1},{1,0}};
        
        while(!q.empty()){
            
            vector<pair<int,int>> remove;
            
            if(size == 1){
                pair<int,int> curr = q.front();
                q.pop();
                for(int i=0; i<directions.size(); i++){
                    int tempx = curr.first+directions[i].first;
                    int tempy = curr.second+directions[i].second;
                    
                    if(isValid(tempx,tempy, matrix[0].size(), matrix.size()) && matrix[tempx][tempy] == '1'){
                        q.push({tempx, tempy});
                        remove.push_back({tempx,tempy});
                    }
                    else{
                        return size*size;
                    }
                }
            }
            else{
                int n = 1;
                
                while(n <= elements){
                    
                    if(q.empty()){
                        return size*size;
                    }
                    
                    if(n < elements/2+1){
                        pair<int,int> curr = q.front();
                        q.pop();
                        int tempx = curr.first+directions[0].first;
                        int tempy = curr.second+directions[0].second;

                        if(isValid(tempx,tempy, matrix[0].size(), matrix.size()) && matrix[tempx][tempy] == '1'){
                            q.push({tempx, tempy});
                            remove.push_back({tempx,tempy});
                        }
                        else{
                            return size*size;
                        }
                    }
                    else if(n == elements/2+1){
                        pair<int,int> curr = q.front();
                        q.pop();
                        for(int i=0; i<directions.size(); i++){
                            int tempx = curr.first+directions[i].first;
                            int tempy = curr.second+directions[i].second;

                            if(isValid(tempx,tempy, matrix[0].size(), matrix.size()) && matrix[tempx][tempy] == '1'){
                                q.push({tempx, tempy});
                                remove.push_back({tempx,tempy});
                            }
                            else{
                                return size*size;
                            }
                        }
                    }
                    else{
                        pair<int,int> curr = q.front();
                        q.pop();
                        int tempx = curr.first+directions[2].first;
                        int tempy = curr.second+directions[2].second;

                        if(isValid(tempx,tempy, matrix[0].size(), matrix.size()) && matrix[tempx][tempy] == '1'){
                            q.push({tempx, tempy});
                            remove.push_back({tempx,tempy});
                        }
                        else{
                            return size*size;
                        }
                    }
                    n++;
                }
            }
            
            for(auto i:remove){
                matrix[i.first][i.second] = '0';
            }
            size++;
            elements+=2;
        }
        
        cout<<size<<endl;
        return size*size;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int ans = 0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size();j++){
                
                if(matrix[i][j] == '1'){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    ans = max(ans, bfs(q,matrix));
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