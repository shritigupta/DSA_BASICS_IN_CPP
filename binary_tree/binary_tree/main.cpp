//
//  main.cpp
//  binary_tree
//
//  Created by shritgup on 22/06/21.
//

#include <iostream>
#include<queue>

using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;
    
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
// Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
node* buildTree(){
    int d;
    cout<<"\n enter val: "<<endl;
    cin>>d;
    if(d==-1)
        return NULL;
    
    node *n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void levelOrderPrint(node *root) {
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node *temp = q.front();
        if(temp == NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()) {
                q.push(NULL);
            }
        } else {
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            
        }
    }
    return;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    node *root = buildTree();
    levelOrderPrint(root);
    return 0;
}
