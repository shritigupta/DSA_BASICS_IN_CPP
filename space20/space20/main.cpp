//
//  main.cpp
//  space20
//
//  Created by shritgup on 15/07/21.
//

#include <iostream>
#include<cstring>
using namespace std;

void replace_space(char *str){
    int spacess = 0;
    for(int i =0;str[i] != '\0'; i++){
        if(str[i]==' ')
            spacess += 1;
    }
    int idx = strlen(str) + 2*spacess;
    str[idx] = '\0';
    
    for(int i = strlen(str)-1;i>=0; i--){
        if(str[i] == ' '){
            str[idx-1] = '0';
            str[idx-2] = '2';
            str[idx-3] = '%';
            idx = idx-3;
            
        } else {
            str[idx-1] = str[i];
            idx--;
        }
    }
}

int main(int argc, const char * argv[]) {
    char input[1000];
    cout<<"Enter Paragraph :"<<endl;
    cin.getline(input,1000);
    fflush(stdout);
    replace_space(input);
    cout<<input<<endl;
    return 0;
}
