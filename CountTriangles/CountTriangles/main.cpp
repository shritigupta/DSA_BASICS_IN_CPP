//
//  main.cpp
//  CountTriangles
//
//  Created by shritgup on 18/07/21.
//

#include <iostream>
#include<vector>
#include <unordered_map>
using namespace std;

int count_triangles(vector<pair<int,int>> &points){
    unordered_map<int,int> freq_x;
    unordered_map<int, int> freq_y;
    
    for(auto p:points){
        int x = p.first;
        int y = p.second;
        
        freq_x[x]++;
        freq_y[y]++;
    }
    
    int count = 0;
    for(auto p:points){
        int x =p.first;
        int y = p.second;
        
        int fx = freq_x[x];
        int fy = freq_y[y];
        //cout<<x<<" "<<y<<" "<<fx<<" "<<fy<<endl;
        count += ((fx-1)*(fy -1));
    }
    return count;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<pair<int,int>> points{{1,2},{2,1},{2,2},{2,3},{3,2}};
    cout<<count_triangles(points)<<endl;
   
    return 0;
}
