#include<bits/stdc++.h>
using namespace std;

struct comp{
    bool operator()(pair<int,int> p1, pair<int,int> p2){
        return p1.second > p2.second;
    }
};

class Graphh{
    unordered_map<char, vector<pair<char,int>>> Graph; //adjaceny matrix

    public:
    void addEdge(char nodeA, char nodeB, int weight){ //in dijkastra we have only positive weight
        Graph[nodeA].push_back({nodeB, weight});
        Graph[nodeB].push_back({nodeA, weight}); //dijkstra works on both directed and undirected Graphs.
        
    }

    int shortestPath(char source, char sink){

        if(Graph.find(source) == Graph.end() || Graph.find(sink) == Graph.end()) return -1; //if source or sink is not present int the graph.
        unordered_map<char,int> distance;
        unordered_map<char,int> parent; //this will store from which node we come to this node.

        for(auto i: Graph){ //this is taking O(v)
            distance[i.first] = INT_MAX; //setting add vertices distance to be infinity
        }
        
        priority_queue<pair<char,int>, vector<pair<char,int>> , comp> q; //node, distance

        q.push({source, 0});
        distance[source] = 0;
        parent[source] = -1;


        while(!q.empty()){ //this is taking at max Elog(V) // Where E can range between V to V*V  //sparse graph - complete graph
            pair<char,int> v = q.top(); q.pop();

            if(v.first == sink) break; //if the popped node is sink so we are done.

            for(auto neighbour: Graph[v.first]){
                int relaxDistance = distance[v.first]+neighbour.second;
                if(distance[neighbour.first] > relaxDistance){
                    distance[neighbour.first] = relaxDistance; //relaxing the distance of neighbour nodes.
                    q.push({neighbour.first, relaxDistance});
                    parent[neighbour.first] = v.first;
                }
            }
        }
        //Total time compleixty is O(V+ElogV)

        //min distance
        int finalDistance = distance[sink];


        //path
        cout<<"sink = ";
        while(sink != -1){
            cout<<sink<<" <- ";
            sink = parent[sink];
        }
        cout<<" = source";
        cout<<endl;

        return finalDistance;

    }

    void print(){
        cout<<"Graph: "<<endl;
        for(auto v: Graph){
            cout<<v.first<<": ";
            for(auto p: v.second){
                cout<<"{"<<p.first<<", "<<p.second<<"}"<<" ";
            }
            cout<<endl;
        }
    }
    
};


int main(){
    Graphh g;
    int options;
    while(true){
        cout<<"1.Add Edge  2.Find shortest path 3.Print Graph 4.Quit"<<endl;
        cout<<"Enter a choice ";
        cin>>options;
        cout<<endl;

        char v1, v2;
        int w;
        switch(options){
            case 1:
                cout<<"Enter vertex v1, v2 (char) and weight"<<endl;
                cin>>v1>>v2>>w;
                g.addEdge(v1,v2,w);
                break;
            
            case 2:
                cout<<"Enter source and sink vertex"<<endl;
                cin>>v1>>v2;
                cout<<g.shortestPath(v1,v2)<<endl;
                break;
                

            case 3:
                g.print();
                break;

            default:
                cout<<"Enter a valid option"<<endl;
        }

        cout<<"--------------------------------------------------------"<<endl;
    }
}