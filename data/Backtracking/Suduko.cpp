#include<bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> box(9), row(9), col(9);

int whichBoxRow(int i){
    if(i < 3) return 0;
    if(i < 6) return 1;
    return 2;
}

int whichBoxCol(int j){
    if(j < 3) return 0;
    if(j < 6) return 1;
    return 2;
}

int whichBox(int i, int j){
    int row = whichBoxRow(i);
    int col = whichBoxCol(j);

    return row*3+col;
}

bool validate(){
    // cout<<"validaing "<<endl;
    for(int i=0; i<9;i++){
        // cout<<i<<" "<<row[i].size()<<" "<<col[i].size()<<" "<<box[i].size()<<" "<<endl;
        if(row[i].size() != 9) return false;
        if(col[i].size() != 9) return false;
        if(box[i].size() != 9) return false;
    }
    return true;
}

void print(vector<vector<int>> &mat){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++) cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

bool solve(vector<vector<int>> &mat, int x, int y){

    if(y >= 9){
        x++;
        y = 0;
    }

    if(x >= 9) {
        print(mat);
        return validate();
    }

    if(mat[x][y] == 0){
        for(int no = 1; no <= 9; no++){
            if(row[x].find(no) == row[x].end() && col[y].find(no) == col[y].end()
                && box[whichBox(x, y)].find(no) == box[whichBox(x, y)].end()){
                row[x].insert(no);
                col[y].insert(no);
                box[whichBox(x,y)].insert(no);
                mat[x][y] = no;
                // cout<<"placing "<<x<<" "<<y<<" "<<no<<endl;
                if(solve(mat, x, y+1)) return true;
                mat[x][y] = 0;
                row[x].erase(no);
                col[y].erase(no);
                box[whichBox(x,y)].erase(no);
            }
        }
    }
    else {
        if(solve(mat, x, y+1)) return true;
    }

    return false;
}



int main(){
    
    // write your code here
    int n = 9;
    vector<vector<int>> mat(n, vector<int> (n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            cin>>mat[i][j];
            if(mat[i][j]) {
                row[i].insert(mat[i][j]);
                col[j].insert(mat[i][j]);
            }
        }
    }
    
    for(int i=0; i<9; i+=3){
        for(int j=0; j<9; j+=3){
            for(int x = i; x < i+3; x++){
                for(int y = j; y < j+3; y++){
                    if(mat[x][y]) box[whichBox(x,y)].insert(mat[x][y]);
                }
            }
        }
    }

    if(solve(mat, 0, 0)) cout<<"true";
    else cout<<"false";
    cout<<endl;
    
    return 0;
}