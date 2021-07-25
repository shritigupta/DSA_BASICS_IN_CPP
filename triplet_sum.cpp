//triplet_sum.cpp
//TC O(n^2)
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

vector<vector<int>> triplets(vector<int> arr, int sum) {
	//sort the array
	sort(arr.begin(),arr.end());
	vector<vector<int>> res;
	//pick every a[i], pair sum remaining with 2 pointer approach
	for(int i=0; i<arr.size()-3;i++){
		int j = i+1;
		int k = arr.size()-1;

		//two pointer approach
		while(j<k) {
			int curr_sum = arr[i];
			curr_sum += arr[j];
			curr_sum += arr[k];
			if(curr_sum == sum) {
				res.push_back({arr[i],arr[j],arr[k]});
				j++;
				k--;
			} else if (curr_sum > sum) {
				k--;
			} else {
				j++;
			}

		}
	}
	return res;

}


int main() {
	vector <int> arr{1,2,3,4,5,6,7,8,9,15};
	int S = 18;
	auto result = triplets(arr,S);
	for (auto v:result){
		for(auto no:v){
			cout<<no<<",";
		}
		cout<<endl;
	}

	return 0;
}