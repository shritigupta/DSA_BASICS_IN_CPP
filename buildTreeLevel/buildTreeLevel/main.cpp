//
//  main.cpp
//  buildTreeLevel
//
//  Created by shritgup on 22/06/21.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;
    
    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *levelOrderBuild(vector<int> arr) {
    queue<node *> q;
    node *root = new node(arr[0]);
    q.push(root);
   
    int i = 1;
    int c1 = 0;
    int c2 = 0;
    while(!q.empty() && i < arr.size()) {
        node *curr = q.front();
        q.pop();
        
        c1 = arr[i++];
        c2 = arr[i++];
        
        if(c1 != -1){
            curr->left = new node(c1);
            q.push(curr->left);
        }
        if(c2 != -1) {
            curr->right = new node(c2);
            q.push(curr->right);
        }
    }
    return root;
}

void printLevelOrder(node *root) {
    queue<node *>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node *temp = q.front();
        if(temp == NULL) {
            cout<<endl;
            q.pop();
            if (!q.empty())
                q.push(NULL);
        } else {
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
    return;
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> arr{1,2,3,4,5,-1,6,-1,-1,7,-1,-1,-1,-1};
    node *root = levelOrderBuild(arr);
    printLevelOrder(root);
    return 0;
}
