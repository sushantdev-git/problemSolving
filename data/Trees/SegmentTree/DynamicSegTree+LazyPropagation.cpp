#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node * leftNode = NULL;
    Node * rightNode = NULL;
    int left, right;

    Node(int v, int l, int r){
        val = v;
        left = l,
        right = r;
    }
};

//dynamic seg tree is a dataStructre that allocates memory only when it is needed
//lazy propagation in seg tree is a concept that says only update the nodes when we are using that node 
//we create a copy of seg tree that store by how much we have to update a particular node else it's value is 0
//lazy propagation is generally useful in range update

class DynamicSegTree{ //max dynamic seg Tree
    

    void createNode(Node * root, Node * lazyRoot){
        int mid = (root -> left + root -> right) >> 1;
        
        if(root -> left != root -> right){ //if this is not a leaf node, we will create new node.
            if(!root -> leftNode){
                root -> leftNode = new Node(0, root -> left, mid);
                lazyRoot -> leftNode = new Node(0, root -> left, mid);
            }

            if(!root -> rightNode){
                // cout<<"creating right node"<<endl;
                root -> rightNode = new Node(0, mid+1, root -> right);
                lazyRoot -> rightNode = new Node(0, mid+1, root -> right);
            }
        }
    }

    void updateRootWithLazyRoot(Node * root, Node * lazyRoot){
        root -> val += lazyRoot -> val;
        if(root -> left != root -> right){ //if this is not a leaf node, we will pass the update to child nodes.
            lazyRoot -> leftNode -> val += lazyRoot -> val;
            lazyRoot -> rightNode -> val += lazyRoot -> val;
        }

        lazyRoot -> val = 0;
    }

    void update(int l, int r, int val, Node * root, Node * lazyRoot){
        
        createNode(root, lazyRoot); //we are going to create child node

        updateRootWithLazyRoot(root, lazyRoot); //every time we reach a node we check if it has something to be update with.

        if(root -> right < l || root -> left > r) return; //not in range
        // cout<<"update : "<<l<<" "<<r<<" | "<<root -> left<<" "<<root -> right<<endl;

        if(root -> left >= l && root -> right <= r){ //complete overlap
            if(lazyRoot -> leftNode) lazyRoot -> leftNode -> val += val;
            if(lazyRoot -> rightNode) lazyRoot -> rightNode -> val += val;
            root -> val += val;
            return;
        };

        update(l, r, val, root -> leftNode, lazyRoot -> leftNode);
        update(l, r, val, root -> rightNode, lazyRoot -> rightNode);
        root -> val = max(root -> leftNode -> val, root -> rightNode -> val);
    }

    int query(int l, int r, Node * root, Node * lazyRoot){
        // cout<<"query : "<<l<<" "<<r<<" | "<<root -> left<<" "<<root -> right<<endl;
        if(!root) return -1e9;
        if(l > root -> right || r < root -> left) return -1e9;
        
        updateRootWithLazyRoot(root, lazyRoot); //every time we reach a node we check if it has something to be update with.

        if(root -> left >= l && root -> right <= r) return root -> val;

        return max(query(l, r, root -> leftNode, lazyRoot -> leftNode), query(l, r, root -> rightNode, lazyRoot -> rightNode));
    }

    public: 
    Node * root = new Node(0, 1, 1e9);
    Node * lazyRoot = new Node(0, 1, 1e9);

    DynamicSegTree(int l, int r){
        root = new Node(0, l, r);
        lazyRoot = new Node(0, l, r);
    }

    void update(int l, int r, int v){
        update(l, r, v, root, lazyRoot);
    }

    int query(int l, int r){
        return query(l, r, root, lazyRoot);
    }
};



int main(){
    DynamicSegTree root = DynamicSegTree(0, 1e9);

    int t; cin>>t;
    cout<<t<<endl;
    while(t--){
        int l, r; cin>>l>>r;
        root.update(l, r-1, 1);
        int q = root.query(0, 60);
        cout<<l<<" "<<r<<" "<<q<<endl;
    }
}