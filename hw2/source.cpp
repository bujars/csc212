#include "Sefa_B_HW2.h"

int main(){
#if 0
	//char* arr;
	static char arr[MAXSIZE]; 
	//char arr[] = {'c','d','e'};
	int size = takeUserInputRetSize(arr); 

	for(int i = 0; i < size; i++){
		cout << arr[i] << " "; 
	}
	cout << endl;
//#if 0
	int count = highestOccurances(arr, size); //highestOccurrances(arr, size);
	cout << count << endl;
	
	shiftArray(arr, size, 2);
	for(int i = 0; i < size; i++){
		cout << arr[i] << " "; 
	}
	cout << endl;
//#endif
	static char arr2[MAXSIZE];
	int size2 = takeUserInputRetSize(arr2);
	for(int i = 0; i < size2; i++){
		cout << arr[i] << " "; 
	}
	cout << endl;
	char *a;
	int sizeA = MAXSIZE;
	a = appendAndSort(arr, size, arr2, size2, sizeA);
	
	for(int i = 0; i < sizeA; i++){
		cout << a[i] << " "; 
	}
	cout << endl;
#endif


	char** b;
	//char b[][MAXSIZE];
	size_t m = 100;
	size_t n = 100;
	//mNMatrix(b,m,n);
	b = mNMatrix(m,n);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << b[i][j] << " ";
		}
		cout << endl;
	}

	/*size_t m = 0;
	size_t n = 0;
	b = setMatrix(m,n);
	for(int i = 0;i < m; i++){
		for(int j = 0; j < n; j++){
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	*/
	
	return 0;
}



