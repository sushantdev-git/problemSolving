#include<unordered_map>
using namespace std;

class Node{
    public:
        char data;
        unordered_map<char, Node*> m;
        bool isTerminal;

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
                temp -> m[c] = neww;
                temp = temp -> m[c];
            }
        }

        temp -> isTerminal = true;
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
};