//
//  main.cpp
//  stockspan
//
//  Created by shritgup on 01/07/21.
//

#include <iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> stockSpan(vector<int> price){
    stack<int> st;
    
    int n = price.size();
    vector<int> res(n);
    st.push(0);
    res[0] = 1;


    for(int i = 1; i <= n-1; i++){
        int currpricee = price[i];
        while(!st.empty() and price[st.top()]<=currpricee){
            st.pop();
        }
        if(!st.empty()){
            int prev_high = st.top();
            res[i] = i-prev_high;
        } else {
            res[i] = i+1;
        }
        st.push(i);
    }
    return res;
    
}


int main(int argc, const char * argv[]) {
    vector<int> price{100,80,60,70,60,75,85};
    vector<int> res = stockSpan(price);
    for(int i = 0; i<res.size(); i++){
        cout<<res[i]<<",";
    }
    cout<<endl;
    return 0;
}
