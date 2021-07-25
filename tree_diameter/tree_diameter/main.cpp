//
//  main.cpp
//  tree_diameter
//
//  Created by shritgup on 24/06/21.
//

#include <iostream>
#include<queue>
#include<map>

using namespace std;
class node {
public:
    int val;
    node *left;
    node *right;
    node(int d) {
        val = d;
        left = NULL;
        right = NULL;
    }
} ;

node* buildTree(){
    int d;
    cout<<"enter val : ";
    cin>>d;
    if(d == -1)
        return NULL;
    
    node *n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void levelOrderPrint(node *root) {
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        node *temp = q.front();
        if(temp == NULL){
            q.pop();
            cout<<endl;
            if(!q.empty())
            q.push(NULL);
        } else {
            q.pop();
            cout<<temp->val<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return;
}


int height(node *root)  {
    if(root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return(1+max(lh,rh));
}

int diameter(node *root){
    if(root==NULL)
        return 0;
    int d1 = height(root->left) + height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);
    return max(d1,max(d2,d3));
}

class hdpair{
public:
    int height;
    int diameter;
};


hdpair diameter_opt(node *root) {
    hdpair p;
    if(root == NULL) {
        p.height=p.diameter=0;
        return p;
    }
    hdpair Left= diameter_opt(root->left);
    hdpair Right = diameter_opt(root->right);
    
    p.height=max(Left.height,Right.height)+1;
    int D3= Left.height+Right.height;
    int D1 = Left.diameter;
    int D2 = Right.diameter;
    p.diameter =max(D3,max(D1,D2)) ;
    return(p);
    
}

int height_tree(node *root) {
    if(root == NULL)
        return 0;
    
    int h1 = height_tree(root->left);
    int h2 = height_tree(root->right);
    return 1+max(h1,h2);
}

int replacewithsum(node *root){
    if(root == NULL)
        return 0;
    
    if(root->left == NULL and root->right == NULL)
        return root->val;
    
    int temp = root->val;;
    
    int l = replacewithsum(root->left);
    int r = replacewithsum(root->right);
    root->val = l+r;
    return(temp+root->val);
    
}

bool isheightbalanced_tree(node *root){
    if(root==NULL)
        return true;
    
    int h1 = height(root->left);
    int h2 = height(root->right);
    
    bool l = isheightbalanced_tree(root->left);
    bool r = isheightbalanced_tree(root->right);
    
    return(abs(h1-h2)<=1 and l and r);
    
}


pair<int,bool> isheightbalanced_tree_opt(node *root){
    pair<int,bool> p,Left,Right;
    if(root==NULL){
        p.first = 0;
        p.second = true;
        return p;
    }
    Left = isheightbalanced_tree_opt(root->left);
    Right = isheightbalanced_tree_opt(root->right);
    int height = max(Left.first,Right.first) + 1;
    
    if(abs(Left.first-Right.first)<=1 and Left.second and Right.second)
        return make_pair(height,true);
    
    return make_pair(height, false);
    
}

void traverseTree(node *root,map<int,vector<int>> &m,int d) {
    if(root == NULL)
        return;
    
    m[d].push_back(root->val);
    traverseTree(root->left, m,d-1);
    traverseTree(root->right,m,d+1);
}



void verticalOrderPrint(node *root) {
    map<int,vector<int>> m;
    int d = 0;
    traverseTree(root, m, d);
    
    // -1 ->(..) 0 ->(...)
    for(auto p:m) {
        vector<int> line = p.second;
        for(auto data: line){
            cout<<data<<" ";
        }
        cout<<endl;
    }
        
}

class Pair{
public:
    int inc;
    int exc;
};

Pair maxSubSetSum(node *root) {
    Pair p;
    if(root == NULL) {
        p.inc = p.exc = 0;
        return p;
    }
    Pair left = maxSubSetSum(root->left);
    Pair right = maxSubSetSum(root->right);
    
    p.inc = root->val+left.exc+right.exc;
    p.exc=max(left.inc,left.exc)+max(right.inc,right.exc);
    
    return p;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    node *root = buildTree();
    levelOrderPrint(root);
    cout<<endl;
    cout<<"diameter : "<<diameter(root)<<endl;
    
    hdpair n = diameter_opt(root);
    cout<<"optimized diameter : "<<n.diameter<<endl;

    cout<<"height of tree : "<<height_tree(root)<<endl;
    
    cout<<"is height balanced :"<<isheightbalanced_tree(root)<<endl;
    
    cout<<"is height balanced optimised:"<<isheightbalanced_tree_opt(root).second<<endl;
    
    
    verticalOrderPrint(root);
    
    Pair p =maxSubSetSum(root);
    cout<<"Max Subset Sum :"<<max(p.inc,p.exc)<<endl;
    
    int num= replacewithsum(root);
    
    levelOrderPrint(root);
    cout<<endl;
    return 0;
}
