//
//  main.cpp
//  runningmedian
//
//  Created by shritgup on 10/07/21.
//

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    
    priority_queue<int> leftheap; //max
    priority_queue<int,vector<int>,greater<int>> rightheap; //min
    
    int d;
    cout<<"enter value"<<endl;
    cin>>d;
    leftheap.push(d);
    
    float med = d;
    cout<<med<<" ";
    
    cin>>d;
    while(d != -1){
        if(leftheap.size() > rightheap.size()) {
            if(d < med){
                rightheap.push(leftheap.top());
                leftheap.pop();
                leftheap.push(d);
            } else {
                rightheap.push(d);
            }
            med = (leftheap.top() + rightheap.top()) /2.0;
        } else if(leftheap.size() == rightheap.size()) {
            if(d<med) {
                leftheap.push(d);
                med = leftheap.top();
            } else {
                rightheap.push(d);
                med = rightheap.top();
            }
        } else {
            if(d<med){
                leftheap.push(d);
            } else {
                leftheap.push(rightheap.top());
                rightheap.pop();
                rightheap.push(d);
            }
            med = (leftheap.top() + rightheap.top()) /2.0;
        }
        cout<<med<<" ";
        cin>>d;
    }
    
    
    return 0;
}
