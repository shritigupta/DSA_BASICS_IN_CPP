//
//  main.cpp
//  minimumcostropejoining
//
//  Created by shritgup on 10/07/21.
//

#include <iostream>
#include<queue>

using namespace std;

int min_cost_join(int ropes[],int n){
    priority_queue<int,vector<int>,greater<int>> pq(ropes,ropes+n);
    
    int cost = 0;
    while(pq.size() > 1){
        int A = pq.top();
        pq.pop();
        
        int B = pq.top();
        pq.pop();
        
        int C = A+B;
        cost += C;
        pq.push(C);
    }
    return cost;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N = 4;
    int ropes[]={4,3,2,6};
    cout<<min_cost_join(ropes,N)<<endl;
    return 0;
}
