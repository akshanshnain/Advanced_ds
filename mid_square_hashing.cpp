// C++ program to illustrate the 
// mid-square hashing technique 
#include <ctime> 
#include <iostream> 

using namespace std; 

// Returns a seed value based on current system time. 
long long int newTime() 
{ 

	// Acquiring number of seconds 
	// passed from Jan 1, 1970. 
	time_t t = time(NULL); 

	// Converting the time to year, month, 
	// day, hour, minute, and second. 
	struct tm* tm = localtime(&t); 
	long long int x; 

	// Applying a certain logic to get 
	// required number of digits. It may vary. 
	x = (tm->tm_hour) * 10000000 + (tm->tm_min) * 100000 
		+ (tm->tm_sec) * 1000 + (tm->tm_mday) * 10 + (tm->tm_year); 

	// Return the calculated number. 
	return x; 
} 

// Returns a random 8-digit key. 
long int getKey() 
{ 

	// Taking the key from system time. 
	// returns a 8-digit seed value. 
	static long long int key = newTime(); 

	// Squaring the key. 
	key = key * key; 

	// Extracting required number of digits ( here, 8 ). 
	if (key < 1000000000000000) { 
		key = key / 10000; 
		key = key % 100000000; 
	} 
	else { 
		key = key / 10000; 
		key = key % 100000000; 
	} 

	// Returning the key value. 
	return key; 
} 

// Driver Code 
int main() 
{ 
	// get the first key 
	std::cout << getKey() << endl; 

	// get the second key 
	std::cout << getKey() << endl; 
	return 0; 
} 
