//
//  main.cpp
//  bst
//
//  Created by shritgup on 26/06/21.
//

#include <iostream>
#include<vector>

using namespace std;

class Node {
public:
    int key;
    Node *left;
    Node *right;
    
    Node(int key) {
        this->key = key;
        left = right = NULL;
    }
};

Node *insert(Node *root, int key){
    if(root== NULL){
        return new Node(key);
    }
    if(key<root->key) {
        root->left = insert(root->left,key);
    } else {
        root->right = insert(root->right,key);
    }
    return root;
}

void inorder(Node *root){
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

bool isPresent(Node *root, int key) {
    if(root == NULL)
        return false;

    if(root->key == key) {
        return true;
    }else if(root->key > key){
        return isPresent(root->left, key);
    } else {
        return isPresent(root->right,key);
    }
}

Node * sortedArrayToBST(vector<int>arr, int start,int end){
    if(start>end)
        return NULL;
    
    int mid = (start+end)/2;
    Node *root = new Node(arr[mid]);
    root->left = sortedArrayToBST(arr,start,mid-1);
    root->right = sortedArrayToBST(arr,mid+1, end);
    return root;
}

int closest(Node *root, int target) {
    if(root == NULL)
        return -1;
    int min_so_far = INT_MAX;
    int ans = INT_MIN;
    Node *temp = root;
    while(temp) {
        int curr_diff = abs(temp->key-target);
        
        if (curr_diff == 0) {
            return temp->key;
        }
        
        if(curr_diff < min_so_far) {
            min_so_far = curr_diff;
            ans = temp->key;
        }
        
        if(temp->key < target)
            temp = temp->right;
        else
            temp= temp->left;
        
    }
    return ans;
}

class LinkedList{
    public:
    Node *head;
    Node *tail;
};


LinkedList  flatten_list(Node *root) {
    LinkedList l;
    if(root == NULL) {
        l.head = l.tail = NULL;
        return l;
    }
    
    //4 cases
    if(root->left == NULL and root->right==NULL){
        l.head= l.tail = root;
        return l;
    }
    else if(root->left != NULL and root->right== NULL){
        LinkedList leftll = flatten_list(root->left);
        leftll.tail->right = root;
        
        l.head = leftll.head;
        l.tail = root;
    }
    else if (root->right != NULL and root->left == NULL) {
        LinkedList rightll = flatten_list(root->right);
        root->right = rightll.head;
        l.head = root;
        l.tail = rightll.tail;
    }
    else {
        LinkedList leftll = flatten_list(root->left);
        LinkedList rightll = flatten_list(root->right);
        leftll.tail->right = root;
        root->right = rightll.head;
        l.head  = leftll.head;
        l.tail = rightll.tail;
    }
    
    return l;
}


Node *inorderSucc(Node *root,Node *target){
    if(target->right != NULL) {
        Node *temp = target->right;
        while(temp->left) {
            temp = temp->left;
        }
        return temp;
    }
    
    Node *temp = root;
    Node *succ = NULL;
    while(temp) {
        if(temp->key > target->key) {
            succ =temp;
            temp=temp->left;
        } else if(temp->key < target->key) {
            temp = temp->right;
        }else
            break;
    }
    return succ;
}

bool inrange(Node *root, int start, int end){
    if(root == NULL)
        return true;
    if(root->key < start or root->key > end)
        return false;

        return inrange(root->left, start, root->key-1) and
                inrange(root->right,root->key+1,end);
}


bool isBst(Node *root){
    return inrange(root, INT_MIN, INT_MAX);
}


Node* lca(Node*root, int a, int b){
    //Complete this function and return address of the node
    if(root == NULL)
        return NULL;
    /*
    if((root->key<a and root->key>b) or
        (root->key > a and root->key < b))
        return root;
    */
    if(root->key > a and root->key > b)
        return  lca(root->left,a,b);
    
    if(root->key <  a and root->key < b)
        return lca(root->right,a,b);
    
    return root;
}


int main() {
    Node *root = NULL;
    vector<int> a{8,3,10,1,6,14,4,7,13};
    
    for(auto x: a) {
        root = insert(root,x);
    }
    inorder(root);
    cout<<endl;
    cout<<isPresent(root, 3);
    cout<<endl;
    /* Give here sorted_array as inout then uncomment
     int n= a.size();
    Node * temp = sortedArrayToBST(a, 0 , n-1);
    inorder(temp);
    cout<<endl;
     */
    cout<<closest(root, 12)<<endl;
    
    cout<<"IsBst : "<<isBst(root)<<endl;
    
    cout<<"LCA : "<<lca(root,4,7)->key<<endl;
    
    Node *t1 = root->left->right->right;
    Node *t2 = root->right;
    
    cout<<"Inorder succ of 7 is: "<<inorderSucc(root, t1)->key <<endl;
    cout<<"Inorder succ of 10 is: "<<inorderSucc(root, t2)->key <<endl;

    
    
    
    LinkedList l = flatten_list(root);
    
    Node *temp = l.head;
    while(temp){
        cout<<temp->key<<" ";
        temp = temp->right;
    }
    cout<<endl;
    
    
    
    return 0;
}
