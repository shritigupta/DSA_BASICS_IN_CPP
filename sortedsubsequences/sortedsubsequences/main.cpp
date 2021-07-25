//
//  main.cpp
//  sortedsubsequences
//
//  Created by shritgup on 16/07/21.
//

#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>

using namespace std;

void subsequence(string s,string o, vector<string> &v){
    //base case
    if(s.size()==0){
        v.push_back(o);
        return;
    }
    
    //rec case
    char ch = s[0];
    string reduced_inout = s.substr(1);
    //includes
    subsequence(reduced_inout, o+ch, v);
    //excludes
    subsequence(reduced_inout, o, v);
}

bool compare(string s1,string s2){
    if(s1.length() == s2.length())
        return s1<s2;
    else
        return s1.length()<s2.length();
}

int main(int argc, const char * argv[]) {
    string s = "abcd";
    vector<string> v;
    string output="";
    subsequence(s,output,v);
    
    sort(v.begin(),v.end(),compare);
    
    for(auto s:v){
        cout<<s<<" , ";
    }
    cout<<endl;
    return 0;
}
