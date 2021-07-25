//
//  main.cpp
//  RecursionLadder
//
//  Created by shritgup on 20/07/21.
//

#include <iostream>

using namespace std;

int num_ways(int n){
    if(n<0)
        return 0;
    
    if(n==0)
        return 1;
    
    int n1 = num_ways(n-1);
    int n2 = num_ways(n-2);
    int n3  = num_ways(n-3);
    return n1+n2+n3;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<num_ways(4)<<endl;
    
    return 0;
}
