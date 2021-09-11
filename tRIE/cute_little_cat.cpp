#include <iostream>
#include <vector>
#include "implementation.h"
using namespace std;


void searchHelper(Trie t, int i, string doc, unordered_map<string, bool>& map){

    Node* temp = t.root;

    for(int j=i; j<doc.size(); j++){

        char ch = doc[j];
        if(temp -> m.count(ch) == 0){
            return; //means we do not find that char in trie
        }

        temp = temp -> m[ch];
        if(temp -> isTerminal){
            string out = doc.substr(i,j-i+1); //those substring that we find in trie we 
            //store that in a map.
            map[out] = true;
        }

    }

    return;

}

void documentSearch(string doc, vector<string> words) {
    Trie t;

    //creating trie
    for(auto word: words) {
        t.insert(word); //time complexity O(n*w)
    }

    unordered_map<string, bool> map;
    //searching in document
    //and insert all the substring we find in document and trie both
    for(int i = 0; i <doc.size(); i++){
        searchHelper(t,i, doc, map);
    }

    for(auto w: words){
        if(map[w]){
            cout<<w <<" : True"<<endl;
        }
        else{
            cout<<w <<" : False"<<endl;
        }
    }

}

int main(){
    string document = "little cute cat loves to code in c++, java & python";
    vector<string> words = {"cute cat", "ttle", "cat", "quick", "big"};

    documentSearch(document, words);
    return 0;
}