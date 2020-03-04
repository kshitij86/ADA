#include <bits/stdc++.h>
using namespace std; 

int printList(int x[], int n){
	for(int i = 0 ; i < n; i++){
		cout << x[i] << " "; 
	}
	cout << endl; 
}


int main(void){

	int arr[] = {12, 3, 455, 34, 56}; 
	int size = sizeof(arr)/sizeof(arr[0]); 
	int target = 455; 
	int low(0), high(size);

	// List must be sorted for binary search. 
	std::sort(arr, arr+size);

	printList(arr, size); 

	for(int i = 0; i < size; i++){

		int mid = (low + (high-1))/2;
		
		if(arr[mid] == target){
			cout << target <<" found at: " << mid+1 << endl;  
			return 0; 
		}
	
		if(arr[mid] < target){
			low = mid+1; 
		}
		
		if(arr[mid] > target){
			high = mid-1; 
		}
		
	}

	cout << target <<" not found in this list.\n";
	return 0; 
}