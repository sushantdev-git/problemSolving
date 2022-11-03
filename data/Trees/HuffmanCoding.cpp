#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

class TreeNode{
    public:
    char data;
    int frequency;
    TreeNode* left = NULL;
    TreeNode* right = NULL;

    TreeNode(char data, int frequency){
        this->data=data;
        this->frequency=frequency;
    }
};

class Compare{
    public:
    bool operator()(TreeNode* node1, TreeNode* node2){
        return node1->frequency>node2->frequency;
    }
};

void getFrequencyMap(map<char, int> &freq, string s){
    for(int i=0;i<s.length();i++){
        freq[s[i]]++;
    }
}

void printCodes(TreeNode* root, string code){
    if(root==NULL)
        return;

    if(root->data!='$')
        cout<<root->data<<"  :  "<<code<<endl;

    printCodes(root->left, code+"0");
    printCodes(root->right, code+"1");
}

void inorder(TreeNode* root){
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);
}

void createHuffmanTree(map<char, int> freq){
    
    priority_queue<TreeNode*, vector<TreeNode*>, Compare> pq;
    for(auto i:freq){
        pq.push(new TreeNode(i.first, i.second));
    }

    TreeNode* top;
    TreeNode* left;
    TreeNode* right;
    while(pq.size() > 1){
        left=pq.top();
        pq.pop();

        right=pq.top();
        pq.pop();
        top=new TreeNode('$',left->frequency+right->frequency);
        top->left=left;
        top->right=right;
        pq.push(top);

    }

    TreeNode* root = pq.top();

    printCodes(pq.top(),"");
}

int main(){
    string s;
    cin>>s;

    map<char, int> freq;
    getFrequencyMap(freq, s);
    createHuffmanTree(freq);
    
}