//
//  main.cpp
//  MinDiff
//
//  Created by shritgup on 20/06/21.
//

#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

pair<int,int> minDifference(vector<int> a,vector<int> b){
    //Complete this method
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    pair<int,int> res;
    
    int n1 = a.size();
    int n2 = b.size();
    
    int i = 0;
    int j =0;
    int min_diff = INT_MAX;
    
    while(i<n1 and i<n2){
        if(min_diff>abs(a[i]-b[j])){
            min_diff = abs(a[i]-b[j]);
            res.first = a[i];
            res.second = b[j];
        }
        if(a[i]<b[j])
            i++;
        else
            j++;
    }
    
    
    return res;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a{23,5,10,17,30};
    vector<int> b{26,134,135,14,19};
    pair<int,int> res = minDifference(a,b);
    cout<<res.first<<" "<<res.second<<endl;
    return 0;
}
