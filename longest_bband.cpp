//longest band
#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

int longest_chain(vector<int> arr) {
	unordered_set<int> s ;
	int largest_len=1;
	for(int x:arr) {
		s.insert(x);
	}

	for(auto elt: arr) {
		int parent = elt-1;

		if(s.find(parent) == s.end()) {
			int next_no = elt+1;
			int cnt = 1;
			
			while(s.find(next_no) != s.end()) {
				next_no++;
				cnt++;
			}

			largest_len = max(largest_len,cnt);
		}
	}
	return largest_len;
}




int main() {
	vector<int> arr{1,9,3,0,18,5,2,4,10,7,12,6};

	cout<<longest_chain(arr)<<endl;
	return 0;
}