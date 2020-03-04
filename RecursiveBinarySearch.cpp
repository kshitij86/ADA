#include <bits/stdc++.h>
using namespace std; 


// Always a pointer to the array is passed.
int binarySearch(int val[], int low, int target, int high){

	// Required.
	std::sort(val, val+high);

	if(high >= 1){
		int mid = (low + (high-1))/2; 

		// If mid is the target.
		if(val[mid] == target)
			return mid; 

		// If val[mid] is less than target. 
		if(val[mid] < target)
			return binarySearch(val, mid+1, target, high); 

		// If val[mid] is bigger than target. 
		if(val[mid] > target)
			return binarySearch(val, low, target, mid-1);
	}

	// Not found. 
	return -1;

}

int main(void){
	
	int vals[] = {17,2,356,4333,5,96}; 
	int n = sizeof(vals)/sizeof(vals[0]);
	int tar = 90; 

	cout << "Element found at: " << binarySearch(vals, 0, tar, n-1); 

	return 0;	
}