//
//  main.cpp
//  simplify
//
//  Created by shritgup on 01/07/21.
//

#include <iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace  std;

string simplifyPath(string path){
    
    //Identify tokens
    istringstream iss(path);
    vector<string> tokens;
    string token;
    while(getline(iss,token,'/')){
        
        if(token=="." or token=="")
            continue;
        tokens.push_back(token);
    }
    

    vector<string> stack;
    
    if(path[0]=='/'){
        //denotess that our path iss an abs path with root dir
        stack.push_back("");
    }
    
    for(string token:tokens){
        if(token==".."){
            //Absolute path or relative path
            if(stack.size()==0 or stack[stack.size()-1]==".."){
                stack.push_back("..");
            }
            
            else if(stack[stack.size()-1]!=""){
                stack.pop_back();
            }
        } else {
            stack.push_back(token);
        }
    }
    
    //combine all element in stack to get answer
    if(stack.size() == 1 and stack[0]==""){
        return"/";
    }
    ostringstream oss;
    int i =0;
    for(auto token:stack){
        if(i != 0 ){
            oss<<"/";
        }
        i++;
        oss << token;
    }
    
    return oss.str();
    
}





int main(int argc, const char * argv[]) {
    // insert code here...
    string path = "/../x/y/../z/././w/a///../../c/./";
    cout<<simplifyPath(path)<<endl;
    return 0;
}
