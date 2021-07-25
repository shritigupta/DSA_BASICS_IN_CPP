//
//  main.cpp
//  rpg
//
//  Created by shritgup on 27/06/21.
//

#include <iostream>
#include <vector>

using namespace std;

int min_swap(int N, vector<int>X, vector<int> Type) {
    vector<int> x_1;
    int tot_obs = 0;
    int tot_hero = 0;
    
    //total_obstacles and total heros
    //type1 array
    for(int i = 0; i<N; i++){
        if(Type[i] == 1){
            x_1.push_back(X[i]);
            if (tot_hero == 0)
                tot_hero += X[i] ;
            else {
                tot_hero = tot_hero -1;
                tot_hero += X[i];
            }
        } else
            tot_obs += Type[i];
    }
    
    if(tot_hero < tot_obs)
        return -1;
    //sorting type 1 array for minimum swap
    sort(x_1.begin(),x_1.end(),greater<int>());
    
    
    int min_split = 0;
    int temp_hero = 0;
    
    //break when type 1 hero >= total_obs
    for(int i = 0; i<x_1.size(); i++){
        if (temp_hero == 0)
            temp_hero += X[i] ;
        else {
            temp_hero = tot_hero -1;
            temp_hero += X[i];
        }
        min_split++;
        if(temp_hero >= tot_obs)
            break;
    }
    return min_split;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    int N = 3;
    vector<int> X{4,3,2};
    vector<int> Type{1,1,2};
    cout<<min_swap(N,X,Type)<<endl;
    return 0;
}
