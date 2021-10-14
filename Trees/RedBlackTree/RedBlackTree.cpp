#include<iostream>
using namespace std;

/*
    Red-black tree is a binary search tree
    we need maximum of log n time to insert,search and delete in Binary tree
    so we have AVL Tree for that, but in AVL we might have to do many rotations to make
    the tree balanced.

    So in that case we need Red black tree.

    In Red black tree node can be red or black
    In Red black tree we might have to at most 2 rotations 
    Red black tree guarentees logn time compleixty

    when to use AVL vs RedBlack
        - AVL Tree faster lookup as strictly height balanced.
        - RedBlack faster insertion and deletion and less rotations requried.


    Properties of red black tree
        - it a a self balancing tree
        - every node is either Black or Red and root is always Black
        - Every leaf which is NUll is Black 
        - If node is red then it's children are black.
        - Every path form a node to any of its descedent NUll node 
            has same no of Black nodes. 
        - It is roughly height balanced. (AVL tree is strictly height balanced.) 
        - the relation between shortest path and longest path from root node is longest path at miximum can be twice of shortest path.
            for example longest path consist sequence of nodes B R B R B R B R
            and shortest path consist B B B B 
            //if longest path is greater  that twice of shortest path then it is not red black tree. 

    Insertion in Red black tree.
        1 if tree is empty, create newnode as root node with color black
        2 if tree is not empty, create newnode as leaf node with color red.
        3 if parent of newnode is black then exit.
        4 if parent of newNOde is Red, then check the color of parent  siblings of newNode
            a if color is black of NUll then do suitable rotation and recolor
            b if color is Red then recolor and also check if parent's parent of newNode is
              not the root node then recolor it & recheck.
*/

enum Color{Black, Red}; //0, 1


struct Node{
    int data;
    Node * left = NULL; 
    Node * right = NULL;
    Node * parent = NULL;
    bool color = Black; 
};

class RedBlackTree {
    Node * root;
    public:
        RedBlackTree(){
            root = NULL;// Insertion 1
        }

        void insert(int data){
            
            if(root == NULL){ //if inserted for first time
                root = newNode(data);
                root -> color = Black;
                return ;
            }
            
            Node * temp = root;
            Node * node = newNode(data);
            insertUtil(temp, node);
            cout<<"inserted "<<data<<endl;
            fixViolations(node);
        }

        void inorder(){
            Node * temp = root;
            inroderUtil(temp);
            cout<<endl;
        }

        int height(){
            Node * temp = root;
            return heightUtil(temp);
        }

    private:
        Node * newNode(int data){
            Node * node = new Node(); 
            node -> data = data;
            node -> color = Red; //Insertion 2
            return node;
        }

        Node * leftRotation(Node * node){

            Node * x = node -> right ;
            Node * y = x -> left;
            Node * parent = node -> parent;

            //rotatinggggggg!!!!
            x -> left = node;
            node -> right = y; 

            node -> parent = x;
            x -> parent = parent;

            if(parent != NULL){
                if(parent -> left == node) parent -> left = x;
                else parent -> right = x;
            }

            if(this -> root == node){
                root = x;
            }

            x -> color = Black;
            node -> color = Red;

            return x;
        }

        Node * rightRotation(Node * node){
            //do it on paper else it's hard to uderstand.
            Node * x = node -> left ;
            Node * y = x -> right;
            Node * parent = node -> parent;

            //rotatinggggggg!!!!
            x -> right = node;
            node -> left = y; 

            //setting parents of rotated node
            node -> parent = x;
            x -> parent = parent;

            //setting children of parent of node to x because x is new node.
            if(parent != NULL){
                if(parent -> left == node) parent -> left = x;
                else parent -> right = x;
            }
            //check if node was root, if yes then then new root is x
            if(this -> root == node){
                this -> root = x;
            }

            x -> color = Black;
            node -> color = Red;

            return x;
        }

        Node * insertUtil(Node* root, Node * node){
            if(root == NULL) return node;
            if(root -> data > node -> data){
                root -> left = insertUtil(root -> left,  node);
                root -> left -> parent = root;
            } 
            else{
                root -> right  = insertUtil(root -> right,  node);
                root -> right -> parent = root;
            } 
            return root;
        }

        void fixViolations(Node * node){
            if(node == NULL || node -> parent == NULL) return;
            if(node -> parent == this -> root) return;
            if(node -> parent -> color == Black) return;  //Insert 3

            Node * uncle = NULL;
            Node * parent = NULL;
            Node * grandParent = NULL;
            
            //getting parent, grandparent, and uncle of node.
            if(node -> parent -> parent -> left == node -> parent) {
                uncle = node -> parent -> parent -> right;
                parent = node -> parent;
                grandParent = node -> parent -> parent;
            }
            else {
                uncle = node -> parent -> parent -> left;
                parent = node -> parent;
                grandParent = node -> parent -> parent;
            }

            if(uncle == NULL || uncle -> color == Black){ //Insert 4 a
                
                if(grandParent -> data >= parent -> data && parent -> data > node -> data){ //element is gone in left so we will do right rotation
                   grandParent =  rightRotation(grandParent);
                }
                else if(grandParent -> data <= parent -> data && parent -> data <= node -> data){ //element is gone in right so we will do left rotation
                    //if element was equal to parent it must have been gone in right. so we will check for equal case also
                    grandParent = leftRotation(grandParent);
                }
                else if(grandParent -> data >= parent -> data && parent -> data < node  -> data){ //the data has gone in left and then right
                    leftRotation(parent);
                    grandParent = rightRotation(grandParent);
                }
                else if(grandParent -> data <= parent -> data && parent -> data > node -> data){ //the data has gone in right and then left.
                    rightRotation(parent);
                    grandParent = leftRotation(grandParent);
                }

                // return fixViolations(grandParent); i don't know why fixing the grandparent increase the height of the tree.
                return;

            }

            //if uncle is red; //Insert 4 b
            uncle -> color = Black;
            parent -> color = Black;

            if(grandParent != this -> root) grandParent -> color = Red;

            return fixViolations(grandParent);
        
        }

        void inroderUtil(Node * root){
            if(root == NULL) return;
            inroderUtil(root -> left);
            cout<<root -> data<<" ";
            inroderUtil(root -> right);
        }

        int heightUtil(Node * root){
            if(root == NULL) return -1;
            return max(heightUtil(root -> left)+1, heightUtil(root -> right)+1);
        }



};


int main(){
    RedBlackTree t;
    
    int n,x;
    cin>>n;
    while(n--){
        cin>>x;
        t.insert(x);
        cout<<n<<endl;
    }


    t.inorder();

    cout<<t.height()<<endl;
}