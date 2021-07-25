//
//  main.cpp
//  GraphSShortestPathBFS
//
//  Created by shritgup on 21/07/21.
//

#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }
    
    void addEdge(int i, int j, int unidir=true){
        l[i].push_back(j);
        if(unidir)
            l[j].push_back(i);
    }
    
    void BFS(int source,int dest){
        queue<int> q;
        bool *visited = new bool[V]{0};
        int *dist = new int[V]{0};
        int *parent = new int[V];
        for(int i = 0; i<V; i++)
            parent[i] = -1;
        
        q.push(source);
        visited[source] = true;
        dist[source] = 0;
        parent[source] = source;
        
        while(!q.empty()){
            int f = q.front();
           // cout<<f<<endl;
            q.pop();
            for(auto nbr:l[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = f;
                    dist[nbr] = 1+dist[f];
                }
                
            }
            
        }
        
        for(int i =0; i< V; i++){
            cout<<"Shortest Disstance  to"<<i<<" is"<<dist[i]<<endl;
        }
        
        
        
        if(dest  != -1){
            int temp = dest;
            while(temp != source){
                cout<<temp<<"---";
                temp = parent[temp];
            }
            cout<<source<<endl;
        }
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(0, 4);
    g.addEdge(4, 5);
    g.addEdge(3, 4);
    g.addEdge(5, 6);
    
    g.BFS(1,6);
    return 0;
}
