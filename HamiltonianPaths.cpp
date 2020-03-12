#include<bits/stdc++.h>
using namespace std; 

int V = 4;

int path[4] = {0}, pos = 0, c; 
int graph[4][4] = {{0,0,1,1},
				   {0,0,1,1},
				   {1,1,0,1},
				   {1,1,0,0}}; 

bool createLoop(int r){
	if(graph[r][0] == 1){
		return true; 
	}
	return false;
}

bool isSafe(int r, int c){
	if(graph[r][c] == 1){
		for(int i = 0; i < V; i++){
			if(path[i] == c){
				return false; 
			}
		}
		return true;
	}
	else return false;
}

void write(int path[]){
	for(int i = 0; i < 4; i++) cout << path[i] << " "; 
	cout << endl;
}

void HamilPath(int r){
	if(pos == V){ // At last node, before returning to first.
		if(createLoop(r)){
			// The first and last are joined, this is a solution. 
			write(path); 
			return;
		} else{
			cout << "Disjoint first and terminal nodes."; 
			path[--pos] = -1;  
		}
	} 
	else{
		c = 0;
		while(c <= V-1){
			if(isSafe(r, c)){
				path[pos++] = c;
				// Now continue to explore from this node. 
				HamilPath(c); 
			} c++;
			cout << "No more paths\n";
			path[--pos] = -1; 
		}
	}

}

int main(){

	HamilPath(0);

	return 0; 
}