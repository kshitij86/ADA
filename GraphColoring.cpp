#include<bits/stdc++.h>
using namespace std; 

// The graph and related parameters. 
bool gph[4][4] = {{0,1,1,1},
				  {1,0,1,1},
				  {1,1,0,1},
				  {1,1,1,0}}; 
int totalVertices = 4; 
int x[4] = {0};
int colors = 3; 

int printList(int x[], int n){
	for(int i = 0; i < n; i++){
		cout << x[i] << " "; 
	}
	cout << "\n"; 
}

bool isSafe(int currVertex, int color){
	for(int i = 0; i < totalVertices; i++){
		if(gph[currVertex][i] && x[i] == color)
			return false; 
	}
	return true; 
}

bool graphColor(int currVertex){
	
	// If all vertices are colored. 
	if(currVertex == totalVertices) return true;   

	for(int c = 1; c <= colors; c++){
		if(isSafe(currVertex, c)){
			// Assign this color to this vertex. 
			x[currVertex] = c; 
		
			// Call for the next vertex. 
			if(graphColor(currVertex+1)) return true; 
		}
	}

	// Coloring the graph with given colors is not possible. 
	return false; 
}

int main(){

	// Starting at the first vertex. 
	if(!graphColor(0)){
		cout << "Too few colors to color this grpah.\n"; 
		return 0; 
	} 

	cout << "The graph can be colored as :\n"; 
	printList(x, totalVertices); 

	return 0; 
}