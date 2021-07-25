//
//  main.cpp
//  mergeksorted
//
//  Created by shritgup on 10/07/21.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<int> mergeKArrays(vector<vector<int>> arrays) {
    int k = arrays.size();
    //triplet -> elemt, element idx, array idx
    priority_queue< vector<int>, vector<vector<int>>,greater<vector<int>> > q;
    vector<int>output;
    for(int i =0; i<k; i++){
        int element = arrays[i][0];
        q.push({element,i,0});
    }
    
    while(!q.empty()) {
        auto top = q.top();
        q.pop();
        int element = top[0];
        int a_idx = top[1];
        int e_edx = top[2];
        
        output.push_back(element);
        if(e_edx + 1 < arrays[a_idx].size()) {
            q.push({arrays[a_idx][e_edx+1],a_idx,e_edx+1});
        }
    }
    
    return output;
    
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> arr ={{10,15,20,30},
                                {2,5,8,14,24},
                                {0,11,60,90}};
    
    vector<int> result = mergeKArrays(arr);
    for(auto x:result){
        cout<<x<<" ";
    }
    cout<<endl;
    
    return 0;
}
