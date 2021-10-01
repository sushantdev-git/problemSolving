//AVL trees are auto balancing tree

//in simple binary tree, if we inserted elements in that tree that might lead to skewed 
//treee that is almost like a linked list with 0(n) height


//in avl tree of height of left and right child differ by at most 1
//we can't take max difference to be 0 because it's impossible to make a 
//complete binary tree with even nodes.

//AVL trees are balanced.
//worst case is when right subtree has height 1 more than the left for every node.

//recurrene realtion for height for worst case will be 
//Nh = 1 + N(h-2)//left+ N(h-1)//right

//worst case height of AVL is 2logn or to be needey greedy is 1.44logn

//when ever height difference between left and right subtree is greater that 1 we fix it
//we fix it with help of rotations




#include<iostream>
using namespace std;


class Node
{
    public:
    Node * left = NULL;
    Node * right = NULL;
    int height;
    int data;
};


class AVL{
    Node * root = NULL;

    int height(Node* node){
        if(node == NULL) return -1;
        return node -> height;
    }

    Node * newNode(int data){
        Node * node = new Node(); //inside a class we have to create a object like this i don't know why
        //and also inside main the new keyword is not working
        node -> data = data;
        node -> height = 0;
        return node;
    }

    Node* leftRotation(Node * root){

        Node * x = root -> right ;
        Node * y = x -> left;

        //rotatinggggggg!!!!
        x -> left = root;
        root -> right = y;

        x -> height = max(height(x -> left), height(x -> right))+1; //updating height of tree

        return x;//the new node after rotation
    }

    Node* rightRotation(Node * root){

        Node * x = root -> left ;
        Node * y = x -> right;

        //rotatinggggggg!!!!
        x -> right = root;
        root -> left = y;

        x -> height = max(height(x -> left), height(x -> right))+1; //updating height of tree.

        return x; //the new node after rotation
    }



    Node * inserting(Node * root, int data){

        if(root == NULL) return newNode(data);
        
        if(data <= root -> data) root -> left = inserting(root -> left, data);
        else root -> right = inserting(root -> right, data);
        
        
        int leftHeight = height(root -> left);
        int rightHeight = height(root -> right);
        root -> height = max(leftHeight, rightHeight)+1;

        int balanceFactor = leftHeight - rightHeight;

        //doing all the rotations...
        if(balanceFactor > 1 && data < root -> left -> data) root = rightRotation(root);  //left subtree is more weight && data goes in left of left subtree // LL Rotation
        else if(balanceFactor < -1 && data > root -> right -> data) root = leftRotation(root); //right subtree is more weighted && data goes to right of right subtree. //RR Rotation
        else if(balanceFactor > 1 && data > root -> left -> data){
            //left subtree is more weight and data goes to right of left subtree // LR Rotation
            root -> left = leftRotation(root -> left);
            root = rightRotation(root);
        }
        else if(balanceFactor < -1 && data < root -> right -> data){
            //right subtree is more weighted and data goes to left of right subtree. //RL Rotation
            root -> right = rightRotation(root -> right);
            root = leftRotation(root);
        }

        return root;
    }

    void tree_inroder(Node * root){
        if(root == NULL) return;
        tree_inroder(root -> left);
        cout<<root -> data<<" ";
        tree_inroder(root -> right);
    }

    int tree_search(Node * root, int data){
        if(root == NULL) return -1;
        if(root -> data == data) return 1;
        if(data < root -> data) return tree_search(root -> left, data);
        return tree_search(root -> right, data);
    }

    public:
    
    void insert(int data){
        Node *temp = root;
        root = inserting(temp, data);
    }

    void inorder(){
        //inorder traversal of binary tree gives a sorted array.
        Node * temp = root;
        tree_inroder(root);
    }

    int search(int data){
        //inorder traversal of binary tree gives a sorted array.
        Node * temp = root;
        return tree_search(temp, data);
    }

};



int main(){
    AVL tree;

    int n;
    cout<<"Enter no of nodes : ";
    cin>> n;

    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        tree.insert(x);
    }

    tree.inorder();
    cout<<endl;

    cout<<"Enter an element to find ";
    cin>>x;
    cout<<tree.search(x);
    return -1;
}