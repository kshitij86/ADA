#include<bits/stdc++.h> 
using namespace std;
 
int n=8,cnt=0; int x[9]={0};

// Print the board. 
void printBoard(int x[]){
	
	// Initialize an empty board. 
	char v[n][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++){
			v[i][j] = '-'; 
		}
	}

	// Replace the character at (x[i+1]-1) with Q, and place a queen there.  
	for(int i = 0; i < n; i++){
		v[i][x[i+1]-1] = 'Q';  
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

// Function to check if we have tried all solutions. 
int chk()
{   
	for (int i=1; i<=n; i++){
		if(x[i]!=0) return 0;
	}
	return 1;
}

void write(int x[])
{ 
	cout << " "; 
	for (int i=1; i<=n; i++) 
		cout<<x[i]<<" ";
}

int isattackcol(int c)
{   
	for(int temp=1; temp<=n; temp++){
		if(x[temp]==c) return 1;
	}
	return 0;
}

int isattackdiag(int r, int c)
{   for(int temp=1; temp<=n; temp++)
	{  
		if(x[temp]!=0)
		{  
			if(abs(temp-r) == abs(x[temp]-c)) return 1;
		}
	}
	return 0;
}

void Nqueen(int r)
{ 
	int c=1;
	while(c<=n)
	{   
		int chk1=isattackcol(c);
		int chk2=isattackdiag(r,c);
		
		if(chk1==0 && chk2==0){
			x[r]=c;
			
			if(r==n){

				// Print this solution. 
				
				cout<<"\n Arrangement " << cnt + 1 << ":" << endl; 
				printBoard(x); 
				// Increase solutions by one. 
				cnt++ ;
			} else Nqueen(r+1);
		}
		c++;
	}

	// Trigger backtracking. 		
	x[r]=0;

	// If all queens have been placed. 
	if(chk()==1) {
		cout << "\nNo more outputs"; 
		cout << "\nTotal Solutions: "<< cnt << endl; 
		exit(0);
	}
}

int main()
{ 
	Nqueen(1);
	return 0; 
}