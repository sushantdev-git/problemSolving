#include<bits/stdc++.h>
using namespace std;


bool canPlaceVertically(vector<vector<char>> &mat, int x, int y, string& word){
    int n = word.size();
    // cout<<"canPlaceVertically "<<mat[x][y]<<endl;
    if(x > 0 && mat[x-1][y] != '+') return false;
    if(x + n < 10 && mat[x+n][y] != '+') return false;
    if(x + n-1 >= 10) return false;
    
    int wordCharIndex = 0;
    for(int i = x ; i < x+n; i++){
        if(mat[i][y] != '-' && mat[i][y] != word[wordCharIndex]) return false;
        wordCharIndex++;
    }
    
    return true;
    
}

bool canPlaceHorizontally(vector<vector<char>> &mat, int x, int y, string& word){
    int n = word.size();
    // cout<<"canPlaceHorizontally "<<mat[x][y]<<endl;
    if(y > 0 && mat[x][y-1] != '+') return false;
    if(y + n < 10 && mat[x][y+n] != '+') return false;
    if(y + n-1 >= 10) return false;

    
    int wordCharIndex = 0;
    for(int j = y ; j < y+n; j++){
        if(mat[x][j] != '-' && mat[x][j] != word[wordCharIndex]) return false;
        wordCharIndex++;
    }
    
    return true;
    
}

vector<bool> placeVertically(vector<vector<char>> &mat, int x, int y, string& word){
    vector<bool> placedByMe(word.size(), false);
    int n = word.size();
    int wordCharIndex = 0;
    for(int i=x; i<x+n; i++){
        if(mat[i][y] == '-'){
            placedByMe[wordCharIndex] = true;
            mat[i][y] = word[wordCharIndex];
        }
        wordCharIndex++;
    }
    
    return placedByMe;
}

vector<bool> placeHorizontally(vector<vector<char>> &mat, int x, int y, string& word){
    vector<bool> placedByMe(word.size(), false);
    int n = word.size();
    int wordCharIndex = 0;
    for(int j=y; j<y+n; j++){
        if(mat[x][j] == '-'){
            placedByMe[wordCharIndex] = true;
            mat[x][j] = word[wordCharIndex];
        }
        wordCharIndex++;
    }
    
    return placedByMe;
}


void removeHorizontally(vector<vector<char>> &mat, int x, int y, vector<bool> &placedByMe){
    
    int n = placedByMe.size();
    int placedByMeIndex = 0;
    for(int j=y; j<y+n; j++){
        if(placedByMe[placedByMeIndex]){
            mat[x][j] = '-';
        }
        placedByMeIndex++;
    }
    
}

void removeVertically(vector<vector<char>> &mat, int x, int y, vector<bool> &placedByMe){
    
    int n = placedByMe.size();
    int placedByMeIndex = 0;
    for(int i=x; i<x+n; i++){
        if(placedByMe[placedByMeIndex]){
            mat[i][y] = '-';
        }
        placedByMeIndex++;
    }
    
}

void print(vector<vector<char>> &mat){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++) cout<<mat[i][j];
        cout<<endl;
    }
}

void place(vector<vector<char>> &mat, vector<string> &words, int currword){
    
    // cout<<"place called "<<currword<<endl;

    if(currword >= words.size()){
        print(mat);
        return;
    }
    // print(mat);
    // cout<<endl;
    
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(mat[i][j] != '+'){
                if(canPlaceHorizontally(mat, i, j, words[currword])){
                    vector<bool> placeByMe = placeHorizontally(mat, i, j, words[currword]);
                    place(mat, words, currword+1);
                    // cout<<"removing horizontally "<<words[currword]<<endl;
                    removeHorizontally(mat, i, j, placeByMe);
                    // print(mat);
                    // cout<<endl;
                }
                if(canPlaceVertically(mat, i, j, words[currword])){
                    vector<bool> placeByMe = placeVertically(mat, i, j, words[currword]);
                    place(mat, words, currword+1);
                    // cout<<"removing vertically "<<words[currword]<<endl;
                    removeVertically(mat, i, j, placeByMe);
                    // print(mat);
                    // cout<<endl;
                }
            }
            // cout<<words[currword]<<" "<<i<<" "<<j<<endl;
        }
    }
    // cout<<"returning from "<<words[currword]<<endl;
}


int main(){
    
    // write your code here
    int n = 10;
    vector<vector<char>> mat(n, vector<char>(n));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>mat[i][j];
    }
    
    string s, temp;
    cin>>s;

    vector<string> words;
    for(auto &c: s){
        if(c == ';'){
            words.push_back(temp);
            temp = "";
        }
        else temp+=c;
    }
    words.push_back(temp);
    
    place(mat, words, 0);
    
    return 0;
}