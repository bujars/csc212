#include "Sefa_B_HW2.h"

int main(){

	//char* arr;
	static char arr[MAXSIZE]; 
	//char arr[] = {'c','d','e'};
	int size = takeUserInputRetSize(arr); 

	for(int i = 0; i < size; i++){
		cout << arr[i] << " "; 
	}
	cout << endl;

	int count = highestOccurances(arr, size); //highestOccurrances(arr, size);
	cout << count << endl;
	
	shiftArray(arr, size, 2);
	for(int i = 0; i < size; i++){
		cout << arr[i] << " "; 
	}
	cout << endl;
	
	
	return 0;
}



