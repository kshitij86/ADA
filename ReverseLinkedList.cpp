#include<iostream>
using namespace std; 


// A node in the list. 
struct Node{
	int data; 
	Node* next; 
};

struct Node* head = NULL;  

// Print the linked list. 
void printLinkedList(Node* head){

	struct Node *temp = head; 
	
	while(temp != NULL){
		cout << temp->data << "->"; 
		temp = temp->next; 
	}
	cout << "NULL\n"; 
}


// Insert a new Node in the linked list. 
void insertNode(int value){
	
	struct Node* newNode = new Node();
	
	// Add the node to the list.  
	newNode->data = value;
	newNode->next = NULL;

	if(head == NULL){
		head = newNode; 
	}

	else{
	
	// Else go to last and insert there. 
	struct Node* last = head; 
	while(last->next != NULL) last = last->next; 

	newNode->next = NULL; 
	last->next = newNode; 
	}
}

// Reverse the linked list.
void reverseList(){

	struct Node *prev(NULL), *next(NULL), *curr(head);  

	while(curr != NULL){
		next = curr->next; 
		
		curr->next = prev; 

		prev = curr; 
		curr = next; 
	}

	head = prev; 

	printLinkedList(head); 
} 


int main(void){

	int n = 10; 

	for(int i = 1; i <= n; i++) insertNode(i); 
	printLinkedList(head); 
	
	reverseList(); 
	return 0; 
}