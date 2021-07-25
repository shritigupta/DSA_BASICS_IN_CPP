//
//  main.cpp
//  thequickbrownfox
//
//  Created by shritgup on 18/07/21.
//

#include <iostream>
#include <unordered_set>
#include <climits>

using namespace std;

string s = "thequickbrownfoxjumpsoverthehighbridge";

string words[] = {"the","fox", "thequickbrownfox", "jumps","lazy", "lazyfox",
                    "highbridge", "the", "over", "bridge", "high", "tail",
                    "quick","brown"};

int min_bars_helper(string s,string words[], int idx, unordered_set<string> &m) {
    if(s[idx] == '\0')
        return 0;
    
    int ans = INT_MAX;
    
    string curr_string = "";
    
    for(int j = idx; s[j]!='\0'; j++) {
        curr_string += s[j];
        
        //at every step check if prefix is there or not
        if(m.find(curr_string)!= m.end()){
            int remaining_ans = min_bars_helper(s, words, j+1, m);
            if(remaining_ans != -1){
                ans = min(ans, 1+remaining_ans);
            }
        }
    }
    
    if(ans == INT_MAX){
        return 0;
    }
    return ans;
    
}

int min_bars(){
    unordered_set<string> m;
    
    for(string w:words){
        m.insert(w);
    }
    
    int output = min_bars_helper(s,words, 0, m);
    return output-1;
}

int main(int argc, const char * argv[]) {
    cout<<min_bars()<<endl;
    return 0;
}
