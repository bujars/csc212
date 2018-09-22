#include <iostream>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;


static const size_t MAXSIZE = 100;
//static char data[maxSize];

size_t takeUserInputRetSize(char arr[]);
size_t highestOccurances(char arr[], size_t size);
void shiftArray(int position);
char* appendAndSort(const char* ar1, const size_t ar1Size, const char* ar2, const size_t ar2Size);
void mNMatrix();
void rotateMatrix(int position);
char** enlargeMatrix(size_t size);
