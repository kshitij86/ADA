#include<bits/stdc++.h>
using namespace std; 

map<int, int> mapHD; map<int, int>::iterator itr; 
int rootHD = 0;  


struct TreeNode{
	int data; 
	TreeNode *l,*r; 
};

bool mapCheck(map<int, int> m, int k){

	// If we don't reach the end, it already exists.  
	if(m.find(k) != m.end()) return false; 

	// Otherwise it dosen't. 
	return false; 
}

void printMap(map<int, int> x){
	
	cout << "\n\nHORIZONTAL DISTANCES : \n"; 
	map<int,int>::iterator itr; 
	for(itr = x.begin(); itr != x.end(); ++itr) 
		cout << "NODE ID: " << itr->first << " HD: " << itr->second  << endl;
	cout << endl;  
}

struct TreeNode* insertNode(int val)
{
	TreeNode *temp = new TreeNode; 
	temp->data = val; 
	temp->l = temp->r = NULL; 
	return temp; 
}

void preOrderTraversal(struct TreeNode* root){

	// Base case. 
	if(!root) return;   

	// Pre-order traversal. 
	cout  << root->data << " "; 
	preOrderTraversal(root->l); 
	preOrderTraversal(root->r);  
}

void postOrderTraversal(struct TreeNode* root){

	// Base case. 
	if(!root) return;

	postOrderTraversal(root->l); 
	postOrderTraversal(root->r); 
	cout << root->data << " "; 
}

void inOrderTraversal(struct TreeNode* root){

	// Base case. 
	if(!root) return; 

	inOrderTraversal(root->l); 
	cout << root->data << " ";
	inOrderTraversal(root->r); 
	 
}

// Utility function to make the HD map.  
void verticalSumUtil(struct TreeNode* root, int rootHD=0){

	// Find the horizontal distances of a binary tree. 
	// We need to calculate the horizontal distance for each node. 
	// If we go to the left, subtract one from distance from root. 
	// If we go right, add one to this distance.  

	// Pre-order traversal, and store each node with its HD. 
	if(!root) return; 
	
	mapHD[root->data] = rootHD; 
	verticalSumUtil(root->l, rootHD-1); 
	verticalSumUtil(root->r, rootHD+1); 
}

// Print the tree distances. 
int verticalSum(struct TreeNode* root){
	
	map<int, int>::iterator itr2; 

	int sum[mapHD.size()]; 

	// Map to store each node with its horizontal distance. 
	verticalSumUtil(root, rootHD); 

	printMap(mapHD); 

	return -1; 
}

int main(){

	struct TreeNode* root = insertNode(1); 
	root->l = insertNode(2); 
	root->r = insertNode(3); 
	root->r->r = insertNode(6); 
	root->r->l = insertNode(4);
	root->r->l->r = insertNode(5);
	root->r->l->r->l = insertNode(7); 

	cout << "\n(Pre-order traversal)\n";
	preOrderTraversal(root); 

	cout << "\n(In-order traversal)\n";
	inOrderTraversal(root);

	cout << "\n(Post-order traversal)\n";
	postOrderTraversal(root);

	verticalSum(root);  

	return 0; 
}