#include<bits/stdc++.h>
using namespace std; 

// Does not work. 


bool chk(int x[], int n){
	for(int i = 1; i <= n; i++){
		if(x[i] != 0) return false; 
	}
	return true; 
}

// Check for column conflicts. 
bool isAttackCol(int c, int x[], int n){
	for(int i = 1; i <= n; i++){
		if(x[i] == c) return false; 
	}
	return true; 
}

// Check for diagonal conflicts. 
bool isAttackDiag(int r, int c, int x[], int n){
	for(int i = 1; i <= n; i++){
		if(x[i] != 0){
			if(abs(i-r) == abs(x[i]-c)) return false; 
		}
	}
	return true; 
}

// Print the current board state. 
void printBoard(int x[], int n){
	
	// Initialize an empty board. 
	vector<string> v;
	for(int i = 0; i < n; i++) v[i] = "...."; 

	// Replace the character at x[i+1] with Q, as there is a queen there.  
	for(int i = 0; i < v.size(); i++) v[i].replace(x[i+1], 1, "Q"); 

	for(int i = 0; i < v.size(); i++) cout << v[i] << endl ;
}

void solveNQueens(int n, int r=1){
	int c = 1, cnt = 0;
	int x[5] = {0}; 

	for(int i = 1; i <= n; i++){
		if(!isAttackCol(c, x, n) && !isAttackDiag(r, c, x, n)){
			
			// Place this queen in this column. 
			x[r] = c;  
			
			// A solution has been found. 
			if(r == n){ 
				// Store this solution and print. 
				printBoard(x, n); 
				cnt ++; 
			} 
		
		} else solveNQueens(n, r+1); 
		
		c++; 
	}	

	// Trigger backtracking, go back and choose another column. 
	x[r] = 0; 

	if(chk(x, n)) exit(0); 
}



int main(void){
	
	solveNQueens(4);

	return 0; 
}