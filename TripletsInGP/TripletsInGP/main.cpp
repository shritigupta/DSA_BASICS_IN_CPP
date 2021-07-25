//
//  main.cpp
//  TripletsInGP
//
//  Created by shritgup on 18/07/21.
//

#include <iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int triplets(vector<int> arr, int r){
    int n = arr.size();
    unordered_map<long, long> right,left;
    
    for(auto x:arr){
        right[x]++;
        left[x] = 0;
    }
    
    int ans = 0;
    for(int i =0;i<n; i++){
        right[arr[i]]--;
        
        if(arr[i]%r == 0){
            long b = arr[i];
            long a = arr[i]/r;
            long c = arr[i]*r;
            ans += left[a] *right[c];
        }
        left[arr[i]]++;
    }
    return ans;
}

int main(int argc, const char * argv[]) {

    int r = 4;
    vector<int> arr{1,16,4,16,64,16};
    cout<<triplets(arr,r)<<endl;
    return 0;
}
