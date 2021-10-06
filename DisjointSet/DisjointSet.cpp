#include<iostream>
#include<unordered_map>
using namespace std;

/*This data structure can be find useful to find where an element belongs to same set
  or not 

    This data structure can be used to find cycle in a undirected graph.
    -> whenever we are joining two vertices to form an edge and we find parent node of both vertices is same
      this means both the vertices belongs to same set and if we join them then this will definately from a cycle.

    if we create a simple DSU data structure which does not care about height of tree while joining them
    then this can lead to a skewed tree and the worst case time complexity for this type of DSU will be O(E*V)
        -> for joining of every edge we have to jump v times to find root of the tree.

    DSU can't be used to find cycle in directed graph.

    To optimize the height of the tree we can use the technique of path compression i.e
    line no 31.

    The path compression technique make the find operation time complexity O(logn)

*/

class DisjointSetUnion{
    unordered_map<int,pair<int,int>> sets;
    //we will be storing element in the form of ele = {parent, height}

    int root(int ele){
        //this method is finding root of element. if any element has parent = -1 then it means it is root node.
        if(sets[ele].first == -1) return ele;
        return sets[ele].second = root(sets[ele].first); //this is path compression
        //as we go up the tree we will return the root and the will becom parent of all the elements encountred in path.
    }

    public:
    void addElement(int data){
        if(sets.find(data) != sets.end()) return; 
        sets[data] = {-1, 1}; //{parent, height}
    }

    int find(int a){
        if(sets.find(a) == sets.end()) return -1; //if element is not present in sets
        return root(a); 
    }

    bool union_(int a, int b){
        
        int a_root = find(a);
        int b_root = find(b);

        cout<<a<<" root "<<a_root<<endl;
        cout<<b<<" root "<<b_root<<endl;
        if(a_root == b_root) return true; //if roots of both elements are same then this means this is forming a cycle
        //so we will return true.

        if(sets[a_root].second >= sets[b_root].second){
            //a_root and b_root are roots of a and b, now to maintain the height of tree so it does not get too large
            //what we can do is always make smaller tree children of bigger tree.

            if(sets[a_root].second == sets[b_root].second) sets[a_root].second+=1; 
            //if both tree have same height then height of one tree get increment by 1

            sets[b_root].first = a_root;
        }
        else{
            sets[a_root].first = b_root;
        }

        return false;
    }

    void printElements(){
        for(auto i: sets){
            cout<<i.first<<" = 'parent' -> "<<i.second.first << ", height -> "<<i.second.second<<endl;
        }
        cout<<endl;
    }
};


int main(){
    
    DisjointSetUnion ds;

    int options;
    while(true){
        cout<<"1.Add element  2.Find  3.Union  4.PrintAll  5.Quit"<<endl;
        cout<<"Enter a choice ";
        cin>>options;
        cout<<endl;

        int ele1, ele2;
        switch(options){
            case 1:
                cout<<"Enter an element ";
                cin>>ele1;
                ds.addElement(ele1);
                break;

            case 2:
                cout<<"Enter one element ";
                cin>>ele1;
                cout<<"root of "<<ele1<<" = "<<ds.find(ele1)<<endl;
                break;

            case 3:
                cout<<"Enter two elements ";
                cin>>ele1>>ele2;
                if(ds.union_(ele1, ele2)) cout<<"Union of both form a cycle"<<endl;
                else cout<<"Union completed"<<endl;
                break;

            case 4:
                cout<<"Elements are: "<<endl;
                ds.printElements();
                break;

            case 5:
                return -1;

            default:
                cout<<"Enter a valid option"<<endl;
        }

        cout<<"--------------------------------------------------------"<<endl;
    }

    return -1;
}