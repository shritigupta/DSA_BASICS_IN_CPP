//
//  main.cpp
//  CountRectangles
//
//  Created by shritgup on 18/07/21.
//

#include <iostream>
#include<set>
#include<vector>

using namespace std;
class Compare {
public:
    bool operator()(const pair<int,int> p1, const pair<int,int> p2) {
        if(p1.first == p2.first){
            return p1.second < p2.second;
        }
        return p1.first < p2.first;
    }
};


int countRectangles(vector<pair<int,int>> &v){
    set<pair<int,int>> s;
    
    for(auto p:v){
        s.insert(p);
    }
    
    int ans = 0;
    for(auto it = s.begin(); it != prev(s.end()); it++){
        for(auto jt = next(it); jt != s.end(); jt++){
            pair<int,int> p1 = *it;
            pair<int, int> p2 = *jt;
            
            
            if(p2.first == p1.first or p2.second == p1.second)
                continue;
            
            pair<int,int> p3(p1.first,p2.second);
            pair<int,int> p4(p2.first,p1.second);
            
            if(s.find(p3) != s.end() and s.find(p4) != s.end()){
                ans += 1;
            }
            
        }
        
    }
    return ans/2;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<pair<int,int>> v{{4,1},{4,0},{0,0},{0,1},{1,1},{1,0},{2,0},{2,1}};
    /*v.push_back({4,1});
    v.push_back({4,0});
    v.push_back({0,0});
    v.push_back({0,1});
    v.push_back({1,1});
    v.push_back({1,0});
    v.push_back({2,0});
    v.push_back({2,1});
    */
    cout<<countRectangles(v)<<endl;
    return 0;
}
