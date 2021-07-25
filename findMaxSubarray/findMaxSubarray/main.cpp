//
//  main.cpp
//  findMaxSubarray
//
//  Created by shritgup on 01/07/21.
//

#include <iostream>
#include<vector>
#include<deque>

using namespace std;

void maxSubArrayK(vector<int> a,int k) {
    deque<int> Q(k);
    int i =0;
    int n = a.size();
    //1.Process only first k element
    
    for(i=0; i<k;i++){
        while(!Q.empty() && a[i]>a[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    //Remaining the element of array
    for(;i<n;i++) {
        cout<<a[Q.front()]<<" ";
        while(!Q.empty() and Q.front() <= i-k){
            Q.pop_front();
        }
        while(!Q.empty() && a[i]>a[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> arr{1,2,3,1,4,5,2,3,5};
    int k = 3;
    maxSubArrayK(arr,k);
    return 0;
}
