//
//  main.cpp
//  Anagram
//
//  Created by shritgup on 18/07/21.
//

#include <iostream>
#include <map>
#include<string>
#include<vector>

using namespace std;

vector<int> getHashValue(string s,int i,int j){
    vector<int> freq(26,0);
    for(int k =i; k<=j; k++){
        char ch = s[k];
        freq[ch-'a']++;
        
    }
    return freq;
}




int anagrams_substrings(string s){
    
    map<vector<int>,int> m;
    
    for(int i=0; i < s.length(); i++){
        for(int j=i; j<s.length(); j++){
            vector<int> h = getHashValue(s, i, j);
            m[h]++;
        }
    }
    
    int ans =0;
    for(auto p:m){
        int freq = p.second;
        if(freq>=2){
            ans += (freq*(freq -1)/2);
        }
    }
    
    return ans;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "abba";
    cout<<anagrams_substrings(s)<<endl;
    return 0;
}
