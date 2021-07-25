//
//  main.cpp
//  BusyLife
//
//  Created by shritgup on 20/06/21.
//

#include <iostream>
#include<vector>
#include<algorithm>


using namespace std;

bool SortBySecond(pair<int,int> &a,pair<int,int> &b) {
    return a.second <b.second;
}

int countActivites(vector<pair<int,int> > activities){
    //Complete this method
    int res=1;
    sort(activities.begin(),activities.end(),SortBySecond);
    
    
    
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<pair<int,int>> v{{7,9},{0,10},{4,5},{8,9},{4,10},{5,7}};
    cout<<countActivites(v)<<endl;
    return 0;
}
