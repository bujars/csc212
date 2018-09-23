#include "Sefa_B_HW2.h"


/*NOTE you don't necessarily need to he asserts 
 * in the function besides the one where data is inputted, 
 * but its good to have if any error may occur.*/

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
	assert(size <= MAXSIZE && size > 0);
	size_t hOccurrance = 0;
	char letter = '{';
	size_t countingOccurrance = 0;
	for(size_t i = 0; i < size; i++){
		countingOccurrance= 0;
		//letter = arr[i];
		countingOccurrance++;
		for(size_t j = i+1; j < size; j++){
			if(arr[i] == arr[j]){
				countingOccurrance++;
				arr[j] = arr[size-1];
				size--;
				j--;
			}

		}
		if(countingOccurrance >= hOccurrance){
			if((int)letter > (int)arr[i]){
				letter = arr[i];
				hOccurrance = countingOccurrance; 
			}
		}
		//countingOccurrance = 0;
	}
	cout << letter << endl;
	return hOccurrance;
}
void shiftArray(char arr[], size_t size, int shift){
	assert(size<=MAXSIZE && size >0 );
	if(abs(shift)>size){
		shift = shift%size;
	}
	if(abs(shift)==(-shift)){
		shift = size + shift;
	}
	for(size_t i = 0; i < size/2; i++){
		char temp = arr[i];
		arr[i] = arr[size-1-i];
		arr[size-1-i] = temp;
	}
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	for(size_t i = 0; i <= (shift-1)/2; i++){
		char temp = arr[i];
		arr[i] = arr[shift-1-i];
		arr[shift-1-i] = temp;
	}
		for(int i = 0; i < size; i++){
					cout << arr[i] << " ";
						}
			cout << endl;
	size_t z =1;
	for(size_t i = shift; i < shift+((size-shift)/2); i++){
		char temp = arr[i];
		arr[i] = arr[size-z];
		arr[size-z] = temp;
		z++;
	}
		for(int i = 0; i < size; i++){
					cout << arr[i] << " ";
						}
			cout << endl;
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


