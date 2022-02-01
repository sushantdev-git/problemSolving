#include<iostream>
#include<vector>
#include "implementation.h"
using namespace std;



int main(){

    Trie t;

    vector<string> words = {"apple", "ape", "mango", "news","no", "not", "never"};

    for(string word: words){
        t.insert(word);
    }

    int q;
    cin>>q;

    string search_word;
    while(q--){
        cin>>search_word;
        if(t.search(search_word)){
            cout<<"Yes"<<endl; 
        }
        else{
            cout<<"No"<<endl;
        }
    }
}