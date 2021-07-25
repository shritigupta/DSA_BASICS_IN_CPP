//
//  main.cpp
//  subset_sum
//
//  Created by shritgup on 20/07/21.
//

#include <iostream>
#include<vector>

using namespace std;
int countSubsets(vector<int> arr, int n, int i, int X){
    if(i == n){
        if(X== 0)
            return 1;
        else
            return 0;
    }
    
    int inc = countSubsets(arr, n, i+1, X-arr[i]);
    int exc = countSubsets(arr, n, i+1, X);
    
    return inc+exc;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> arr{1,2,3,4,5};
    
    int X = 10;
    
    cout<<countSubsets(arr,arr.size(),0,X)<<endl;
    
    return 0;
}
