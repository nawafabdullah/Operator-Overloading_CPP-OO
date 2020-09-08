/*
	Nawaf Alharbi
	NOV-2017
	Operater Overloading 
*/

#include "MySet.h"

int main()
{
	int arr[5] = { 4, 55, 22, 1, 3 };
	int arr1[5] = { 2, 255, 22, 1, 3 };

	MySet a(5,arr);

	MySet b(5,arr1);

	MySet c;
	

	cout << a << endl << b;
	

	return 0;
}