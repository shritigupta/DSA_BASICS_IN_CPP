//
//  main.cpp
//  generateBrackets
//
//  Created by shritgup on 20/07/21.
//

#include <iostream>
#include <string>

using namespace std;

void generatparantheses(string o, int n, int open, int close, int i){
    if(i == 2*n) {
        cout<<o<<endl;
        return;
    }
    
    if(open<n){
        o += '(';
        generatparantheses(o, n, open+1, close,i+1);
        o.pop_back();
        //generatparantheses(o+'(', n, open+1, close,i+1);
    }
    if(close < open){
        o += ')';
        generatparantheses(o, n, open, close+1,i+1);
        o.pop_back();
        //generatparantheses(o+')', n, open, close+1,i+1);
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    string output;
    generatparantheses(output,2,0,0,0);
    return 0;
}
