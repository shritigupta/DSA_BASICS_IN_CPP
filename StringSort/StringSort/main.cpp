//
//  main.cpp
//  StringSort
//
//  Created by shritgup on 15/07/21.
//
/*Input*/
/*
 3
 92 022
 82 12
 77 13
 2 false numeric
 
 Output
 82 12
 77 13
 92 022
 */
#include <iostream>
#include<sstream>
#include <string>
#include <vector>
using namespace std;

string extractStringAtKey(string str, int key){
    char *s = strtok((char *)str.c_str()," ");
    while(key>1){
        s= strtok(NULL," " );
        key--;
    }
    
    return (string)s;
}

int convertToInt(string s){
    int ans = 0;
    int p =1;
    for(int i =s.length()-1; i>=0; i--){
        ans += ((s[i]-'0')*p);
        p = p*10;
    }
    return ans;
}


bool lexicoCompare(pair<string,string> s1,pair<string,string> s2 ) {
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;
    return key1<key2;
}

bool numericCompare(pair<string,string> s1,pair<string,string> s2 ) {
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;
    return convertToInt(key1)<convertToInt(key2);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cout<<"start"<<endl;
    cin>>n;
    cin.get(); //consume extra \nn
    
    string temp;
    vector<string> v;
    for(int i =0;i<n; i++){
        getline(cin,temp); //include white spaces
        v.push_back(temp);
    }
    int key;
    string reversal,ordering;
    cin>>key>>reversal>>ordering; //doesnt include white spaces
    
    //1. To extract keys for comparison and store them
    vector<pair<string,string>> vp;
    for(int i =0; i<n; i++){
        vp.push_back({v[i],extractStringAtKey(v[i], key)});
    }
    
    if(ordering == "numeric") {
        sort(vp.begin(),vp.end(),numericCompare);
    } else {
        sort(vp.begin(),vp.end(),lexicoCompare);
    }
    
    if(reversal == "true"){
        reverse(vp.begin(),vp.end());
    }
    
    for(int i=0; i<n; i++){
        cout<<vp[i].first<<endl;
    }
    return 0;
}
