#include <bits/stdc++.h>
using namespace std; 


// Function to print the map. 
void printMap(std::map<char, int> m){
	std::map<char, int>::iterator itr; 

	for(auto itr = m.begin(); itr != m.end(); ++itr) cout << itr->first << "=" << itr->second << " "; 
	cout << endl; 
}

// Check if a given key exists in the map. 
bool checkMap(map<char, int> m, char k){
	if(m.find(k) == m.end()) return false; 
	return true; 
}

char nonRepeatingChar(string s){
	
	// Map and its iterator. 
	map<char, int> mp; 
	map<char, int>::iterator itr; 
	
	for(int i = 0; i < s.length(); i++){
		
		// If the current character is not in the map, add it.  
		if(!checkMap(mp, s[i])) mp[s[i]] = 1;

		// Else update its count. 
		else mp[s[i]] += 1; 
	}

	for(itr = mp.begin(); itr != mp.end(); itr++){
		if(itr->second == 1) return itr->first;  // First non-repeating. 
	}
	return '-'; 
}

int main(){

	string x = "aaabcccdff";  
	
	nonRepeatingChar(x) == '-' ? cout << "All characters repeat." << endl : cout << nonRepeatingChar(x) << endl; 

	return 0; 
} 