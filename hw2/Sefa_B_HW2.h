#include <iostream>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;


static const size_t MAXSIZE = 100;
//static char data[maxSize];

void takeUserInputRetSize(char arr[], size_t& size);
size_t highestOccurances(char arr[], size_t size);
void shiftArray(char arr[], size_t size, int position);
char* appendAndSort(const char* arr1, const size_t arr1Size, const char* arr2, const size_t arr2Size, int& arrSize);
//void  mNMatrix(char** arr, size_t& x, size_t& y);
void rotateMatrix(int position);
char** enlargeMatrix(size_t size, char** c, size_t m, size_t n);
char** mNMatrix(size_t&x, size_t& y);
