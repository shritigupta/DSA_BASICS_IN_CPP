//
//  main.cpp
//  GraphBFS
//
//  Created by shritgup on 21/07/21.
//

#include <iostream>
#include<list>
#include<queue>

using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v){
        V=v;
        l = new list<int>[V];
    }
    void addEdge(int i, int j , bool unidir=true){
        l[i].push_back(j);
        if(unidir)
            l[j].push_back(i);
    }
    
    
    void BFS(int source){
        queue<int> q;
        bool *visited = new bool[V]{0};
        
        q.push(source);
        visited[source] = true;
        
        while(!q.empty()){
            int f = q.front();
            cout<<f <<" "<<endl;
            q.pop();
            
            for (auto nbrs:l[f]){
                if(!visited[nbrs]){
                    q.push(nbrs);
                    visited[nbrs] = true;
                }
            }
            
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
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    
    g.BFS(1);
    
    return 0;
}
