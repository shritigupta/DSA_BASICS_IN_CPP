//
//  main.cpp
//  firstnonrepeatingchar
//
//  Created by shritgup on 30/06/21.
//

#include <iostream>
#include<queue>
#include<map>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    queue<char> q;
    int freq[27] = {0}; //a-z
    
    char ch;
    cin>>ch;
    while(ch != '.') {
        q.push(ch);
        freq[ch-'a']++;
        // remove all char from front of queue untill you get char of freq 1
        while(!q.empty()) {
            int idx = q.front()-'a';
            if(freq[idx]>1){
                q.pop();
            } else {
                cout<< q.front() << endl;
                break;
            }
        }
        if(q.empty()) {
            cout<< -1 <<endl;
        }
        cin>>ch;
    }
    
    
    return 0;
}
