#include<bits/stdc++.h>
#include "leetcodeHelper.h"
using namespace std;

class Node{
    public:
        char data;
        unordered_map<char, Node*> m;
        bool isTerminal;
        Node* parent = NULL;
        string word;
        Node(char d){
            data = d;
        }
};


class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node('\0');
    }

    void insert(string word){
        Node* temp = root;

        for(char c: word){

            if(temp -> m.find(c) != temp -> m.end()){ 
                temp = temp -> m[c];
            }
            else{
                Node* neww = new Node(c);
                neww -> parent = temp;
                temp -> m[c] = neww;
                temp = temp -> m[c];
            }
        }

        temp -> isTerminal = true;
        temp -> word = word;
    }

    bool search(string word){
        
        Node*temp = root;
        int len = 0;
        for(char c: word) {
            if(temp -> m.count(c) == 0){
                return false;
            }
            
            temp = temp -> m[c];
        }

        return temp -> isTerminal;
    }
    
    
    vector<int> whichWordsMatching(string &word, unordered_map<string, int> index ){
        
        queue<pair<Node*, int>> q; //node, diff
        
        Node* temp = root;
        
        int c = 0, tf = 0;
        for(auto &[ch, node]: root -> m){ //24
            if(ch == word[0]) q.push({node, 0});
            else q.push({node, 1});
            c++;
        }
        
        int i=1;
        while(!q.empty() && i < word.size()){
            int n = q.size();
            
            while(n--){
                pair<Node*, int> tem = q.front(); q.pop();
                
                if(tem.second == 0){
                    for(auto &[ch, node]: tem.first -> m){
                        if(ch == word[i] ) q.push({node, 0});
                        else if(ch != word[i]) q.push({node, 1});
                        c++;
                    }
                    tf++;
                }
                else if(tem.second == 1){
                    if(tem.first -> m.find(word[i]) != tem.first -> m.end()){
                        q.push({tem.first -> m[word[i]], tem.second});
                        c++;
                    }
                }
            }
            i++;
        }
        
        vector<int> res;
        // cout<<q.size()<<" ";
        while(!q.empty()){
            pair<Node*, int> p = q.front(); q.pop();
            if(p.second == 0) continue; //same word matched
            if(!p.first -> isTerminal) continue; //not a word
            
            res.push_back(index[p.first -> word]);
            c++;
        }
        
        // cout<<res.size()<<endl;
        cout<<c<<" iterations for word "<<word<<endl;
        
          
        return res;
        
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        
        Trie t;
        
        int n = wordList.size();
        cout<<n<<endl;
        unordered_map<string, int> index;
        for(int i=0; i<n; i++) {
            t.insert(wordList[i]);
            index[wordList[i]] = i; //inverse mapping
        }
        
        if(index.find(endWord) == index.end()) return 0;
        
        queue<pair<string,int>> q;
        
        q.push({beginWord, 1});
        vector<bool> visited(wordList.size(), false);

        int loop = 0;
        
        while(!q.empty()){
            pair<string, int> word = q.front();  q.pop();

            loop++;
            
            if(word.first == endWord) {
                cout<<loop<<endl;
                return word.second;
            }
            
            vector<int> matches = t.whichWordsMatching(word.first, index);
            
            for(auto i : matches){
                if(!visited[i]){
                    q.push({wordList[i], word.second+1});
                    visited[i] = true;
                }
            } 
            
        }
             
        return 0;
        
        
    }
};

int main(){
    Solution s;

    string begin, end, arr;
    cin>> begin >> end >> arr;

    begin = begin.substr(1, begin.size()-2);
    end = end.substr(1, end.size()-2);

    vector<string> words = split(arr, ',');
    
    cout<<s.ladderLength(begin, end, words)<<endl;
}