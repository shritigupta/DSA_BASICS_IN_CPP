//
//  main.cpp
//  findingcabs
//
//  Created by shritgup on 10/07/21.
//

#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

class Car {
public:
    string id;
    int x,y;
    Car(string id,int x,int y){
        this->id = id;
        this->x = x;
        this->y = y;
    }
    int dist() const{
        return x*x + y*y;
    }
};

class CarCompare{
public:
    bool  operator()(const Car a,const Car b)
    {
        return a.dist() < b.dist(); //max heap
    }
};

void printNearestCars(vector<Car> cars, int k){
    
    //create max heap of size k
    priority_queue<Car, vector<Car>, CarCompare> max_heap(cars.begin(),cars.begin()+k);
    for(int i=k; i<cars.size(); i++){
        auto car = cars[i];
        if(car.dist()<max_heap.top().dist()){
            max_heap.pop();
            max_heap.push(car);
        }
    }
    vector<Car> output;
    while(!max_heap.empty()){
        output.push_back(max_heap.top());
        max_heap.pop();
    }
    reverse(output.begin(),output.end());
    for(auto car:output){
        cout<<car.id<<endl;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int  N,K;
    cout<<"Enter N and K"<<endl;
    fflush(stdout);
    cin>>N>>K;
    string id;
    int x,y;
    vector<Car> cars;
    
    for(int i =0; i<N; i++){
        fflush(stdout);
        cin>>id>>x>>y;
        Car car(id,x,y);
        cars.push_back(car);
    }
    printNearestCars(cars,K);
        return 0;
}
