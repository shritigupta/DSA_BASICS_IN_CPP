//mountain.cpp
//TC O(n)
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int highest_mountain(vector<int> a) {
	int n = a.size();
	int large_so_far=0; 

	for(int i =1; i<=n-2; ) {
		//check a[i] is peak or not
		if(a[i]>a[i-1] && a[i]>a[i+1]) {
			//do some work
			int cnt = 1;
			//count backwards
			int j = i;
			while (j>=1 and a[j]>a[j-1]) {
				j--; cnt++;
			}

			//count forwards
			while(i<=n-2 and a[i]>a[i+1]){
				i++; cnt++;

			}
			large_so_far = max(large_so_far,cnt);

		} else {
			i++;
		}
	}
	return large_so_far;

}

int main() {
	vector<int> arr{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};

	cout<<highest_mountain(arr)<<endl;

	return 0;
}
