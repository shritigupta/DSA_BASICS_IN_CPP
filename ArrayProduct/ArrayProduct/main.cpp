//
//  main.cpp
//  ArrayProduct
//
//  Created by shritgup on 20/06/21.
//

#include <iostream>
#include<vector>
using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    
    vector<int> left(n,1);
    vector<int> right(n,1);
    left[0] = arr[0];
    right[n-1] = arr[n-1];
    //update the output array and return
    //complete the code
    for(int i=1; i<n ;i++){
        left[i] = left[i-1]*arr[i];
        right[n-i-1] = right[n-i]*arr[n-i-1];
    }
    output[0]=right[1];
    output[n-1]=left[n-2];
    
    for(int i = 1; i<n-1;i++ ) {
        output[i]=left[i-1]*right[i+1];
    }
    
    return output;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> arr{1,2,3,4,5};
    
    vector<int>res = productArray(arr);
    for(int i =0; i<arr.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
