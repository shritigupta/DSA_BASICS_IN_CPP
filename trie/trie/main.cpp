//
//  main.cpp
//  trie
//
//  Created by shritgup on 03/07/21.
//

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    char data;
    unordered_map<char, Node*> m;
    bool isTerminal;
    
    Node(char d){
        data = d;
        isTerminal = false;
    }
};

class Trie{
public:
    Node *root;
    
    Trie(){
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node *temp = root;
        for(char ch:word){
            if(temp->m.count(ch)==0){
                Node *n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }
    
    bool search(string word){
        
        Node *temp = root;
        for(char ch:word){
            if(temp->m.count(ch) == 0)
                return false;
            temp = temp->m[ch];
        }
        return temp->isTerminal;
        
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    string words[] = {"apple","ape","no","news","not","never"};
    Trie t;
    for(auto w:words){
        t.insert(w);
    }
    string search_words[] = {"apple","no","new"};
    
    for (auto w:search_words) {
        if(t.search(w))
            cout<<w<<":Yes"<<endl;
        else
            cout<<w<<":No"<<endl;
    }
    
    return 0;
}
