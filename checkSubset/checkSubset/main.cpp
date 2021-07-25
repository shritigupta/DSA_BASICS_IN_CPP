//
//  main.cpp
//  checkSubset
//
//  Created by shritgup on 15/07/21.
//

#include <iostream>
#include<string>

using namespace std;

bool isSubset (string str, string subset){
    int i = str.length()-1;
    int j = subset.length() -1;
    
    while(i >= 0 and j >= 0){
        if(subset[j] == str[i])
        {
            i--; j--;
        } else {
            i--;
        }
    }
    if(j == -1)
        return true;
    else
        return false;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    string s1 = "coding minutes";
    string s2 = "oines";
    cout<<isSubset(s1,s2)<<endl;
    return 0;
}
