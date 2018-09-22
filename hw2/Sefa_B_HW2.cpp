#include "Sefa_B_HW2.h"


//Fill array with elements
size_t takeUserInputRetSize(char arr[]){
	char c ;
	size_t size = 0;
	while(size < MAXSIZE && cin >> c && isalpha(c)){
		arr[size] = c;
		size++;
	}	
	return size;
}
size_t highestOccurances(char arr[ ], size_t size){
	//NOTE array is static 
	assert(size < MAXSIZE && size > 0);
	size_t hOccurrance = 0;
	char letter = '{';
	size_t countingOccurrance = 0;
	for(size_t i = 0; i < size; i++){
		letter = arr[i];
		for(size_t j = i+1; j < size; j++){
			if(arr[i] == arr[j]){
				countingOccurrance++;
				arr[j] = arr[size-1];
			}

		}
		if(countingOccurrance >= hOccurrance){
			if((int)letter > (int)arr[i]){
				letter = arr[i];
				hOccurrance = countingOccurrance; 
			}
		}
		countingOccurrance = 0;
	}
	return hOccurrance;
}
void shiftArray(int position){
}

//NOTE ar1 and ar2 are already pre-sorted. //Precondiiton 
char* appendAndSort(const char* ar1, const size_t ar1Size, const char* ar2, const size_t ar2Size){
	char* arr = new char[MAXSIZE];
	arr[0] = 1;
	return arr;
}
void mNMatrix(){
}
void rotateMatrix(int position){
}
char**  enlargeMatrix(size_t size){
	char** arr = new char*[MAXSIZE];
	for(size_t i = 0; i <MAXSIZE; i++){
		arr[i] = new char[MAXSIZE];
	}
	return arr;
}


