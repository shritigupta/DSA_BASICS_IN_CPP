//RainTrapped.cpp


#include<iostream>
#include<vector>

using namespace std;

int trappedWater(vector<int> arr){
	vector<int> left(n,0);
	vector<int> right(n,0);
	int water = 0;

	int n = arr.size();
	if(n<=2)
		return 0;
	left[0] = arr[0];
	right[0]= arr[n-1];

	for(int i=1; i<n; i++) {
		left[i]=max(left[i-1],arr[i]);
	}

	for(int i=n-2; i>=0; i++) {
		right[i]=max(right[i-1],arr[i]);
	}

	//Water trapped at ith index will be min(left side and right side) - height at ith index

	for(int i=0; i<n; i++) {
		water += (min(left[i],right[i]) - arr[i]);

	}

	return water;
}

int main() {
	vector<int> arr{0,1,0,2,1,0,1,3,2,1,2,1};

	cout<<trappedWater(arr)<<endl;
	return 0;
}
