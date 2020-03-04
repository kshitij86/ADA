#include <bits/stdc++.h>
using namespace std;

void printList(int arr[], int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " "; 
	}
	cout << endl;
}

int partition(int arr[], int left,  int right){

	// Taking first as pivot. 
	int pivot = 0; 

	if(left < right){
		while(arr[left] < arr[pivot])
			++left; 
		while(arr[right] > arr[pivot])
			--right;  
		swap(arr[left], arr[right]); 
	}
	if(left > right){
		swap(arr[left], arr[pivot]); 
	}

	return left+1; 
}


int quicksort(int arr[], int l, int r){

	if(l < r){
		// Do it for the first time. 
		int pt = partition(arr, l, r); 

		quicksort(arr, l, pt-1); 
		quicksort(arr, pt+1, r); 
	}
}

int main(void){

	int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    quicksort(arr, 0, n-1);
    printList(arr, n); 

	return 0; 
}