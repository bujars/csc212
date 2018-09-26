#include "Sefa_B_HW2.h"

int main(){
//#if 0
	
	cout << "Testing inputArray" << endl;
	//char* arr;
	size_t size = 0;
	static char arr[MAXSIZE]; 
	//char arr[] = {'c','d','e'};
	takeUserInputRetSize(arr, size); 

	for(int i = 0; i < size; i++){
		cout << arr[i] << " "; 
	}
	cout << endl;

	
//#if 0
//

	int count = highestOccurances(arr, size); //highestOccurrances(arr, size);
	cout << "Testing highest occurance    " << count << endl;
	

	cout << "Testing shift array" << endl;
	shiftArray(arr, size, 2);
	for(int i = 0; i < size; i++){
		cout << arr[i] << " "; 
	}
	cout << endl;
//#endif
	static char arr2[MAXSIZE];
	cout << "Getting a second regular array\n";
	size_t size2 = 2;
	takeUserInputRetSize(arr2, size2);
	for(int i = 0; i < size2; i++){
		cout << arr2[i] << " "; 
	}
	cout << endl;
	char *a;
	int sizeA = MAXSIZE;
	a = appendAndSort(arr, size, arr2, size2, sizeA);
	cout << "appending and sorting two arrays.\n";
	for(int i = 0; i < sizeA; i++){
		cout << a[i] << " "; 
	}
	cout << endl;
//#endif


	char** b;
	//char b[][MAXSIZE];
	size_t m = 2;
	size_t n = 2;
	//mNMatrix(b,m,n);
	cout << "Making 2D matrix\n";
	b = mNMatrix(m,n);
	/*b = new char*[m];
	for(int i = 0; i < m; i++){
		b[i] = new char[n];
		for(int j = 0; j < n; j++){
			b[i][j] = 'a';
			cout << b[i][j] << " ";
		}
		cout << endl;
	
	}*//*
	b[0][0]= 'a';
	b[0][1]= 'b';
	b[1][0] = 'c';
	b[1][1] = 'd';*/
 	//cout << m << " " << n << endl ;
	//size_t m = 0;
	//size_t n = 0;
	//b = setMatrix(m,n);
	for(int i = 0;i < m; i++){
		for(int j = 0; j < n; j++){
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Rotating matrix\n";
	int position = 0;
	rotateMatrix(position, b, m,n);
	//cout << x << " " << y << endl;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << b[i][j] << " ";
		}
		cout << endl;
	}



	
	size_t x  = 100;
	size_t y = 100;
	size_t scale = 2;
	cout << "Enlaarging Matrix " << endl;
	char** biggerMatrix = enlargeMatrix(scale, b, m, n, x, y);
	
	//cout << "Enlaarging Matrix " << x << " " << y << endl;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			cout << biggerMatrix[i][j] << " ";
		}
			cout << endl;
	}

		


	return 0;
}



