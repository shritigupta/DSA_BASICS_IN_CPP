//
//  main.cpp
//  redundantparanthesis
//
//  Created by shritgup on 30/06/21.
//

#include <iostream>
#include<stack>
#include<string>

using namespace std;

bool isRedundant(string str) {
    stack<char> s;
    for(char ch : str){
        if(ch!=')'){
            s.push(ch);
        } else {
            bool operator_found = false;
            
            while (!s.empty() and s.top() != '('){
                char top = s.top();
                if(top=='+' or top =='-' or top == '*' or top == '/') {
                    operator_found = true;
                }
                s.pop();
            }
            s.pop();
            if(operator_found == false) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    string s = "((a+b)+c)";
    cout<<isRedundant(s)<<endl;
    string s1 = "((a+b))";
    cout<<isRedundant(s1)<<endl;
    return 0;
}
