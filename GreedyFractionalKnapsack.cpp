#include <bits/stdc++.h>
using namespace std; 


struct Item
{
	double value, weight, cost; 
	int id;
	Item(double value, double weight, int id){
		this->value = value; 
		this->weight = weight; 
		this->id = id; 
		this->cost = (value/weight); 
	}
};

bool cmp(Item i1, Item i2){
	return i1.cost > i2.cost; 
}

void itemPrinter(struct Item items[], int n){
	for(int i = 0; i < n; i++){
		cout << "ID: " << items[i].id << " COST: " << items[i].cost << endl; 
	}
}

void getMaxvalue(struct Item items[], int n, int capacity){

	// Sort the items according to cost. 
	sort(items, items+n, cmp);

	double maxValue = 0.0; 

	for(int i = 0; i < n; i++){

		// Items to be taken whole. 
		if(capacity - items[i].weight >= 0){
			capacity -= items[i].weight; 
			maxValue += items[i].value; 
		}

		// Items to be taken a fraction of.
		else{
			double fraction = (capacity/items[i].weight);

			maxValue += (fraction * items[i].value); 
			capacity -= (fraction * items[i].weight); 
		}
	}

	itemPrinter(items, n);
	cout << "Capacity left : " << capacity << endl; 
	cout << "Maximum value : " << maxValue << endl; 
}

int main(){

	double cap = 20.0; 
	Item items[] = {{25.0, 5.0, 0}, {12.0, 10.0, 1}, {30.0, 10.0, 2}, {20.0, 8.0, 3}, {5.0, 2.0, 4}};
	
	getMaxvalue(items, 5, cap);

	return 0; 
}