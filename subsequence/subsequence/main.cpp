//
//  main.cpp
//  subsequence
//
//  Created by shritgup on 20/07/21.
//

#include <iostream>
#include <string>
using namespace std;

void subset_get(string s,string o){
    if(s == "\0")
    {
        if(o != "\0")
            cout<<o<<" ";
        if(o == "\0")
            cout<<"o is NULL";
        
        return;
    }
    char ch = s[0];
    
    subset_get(s.substr(1),o);
    /*if(s!= "\0")
        cout<<"debug string :"<<s<<" ";
    if(o != "\0")
        cout<<"exclude :"<<o;
    
    cout<<endl;*/
    
    subset_get(s.substr(1),o+ch);
    /*
    if(s!= "\0")
        cout<<"debug string :"<<s<<" ";
    if(o != "\0")
        cout<<"include : "<<o;
    cout<<endl;*/
    return;
        
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string s = "abc";
    subset_get(s,"\0");
    return 0;
}
