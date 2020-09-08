/*
	Nawaf Alharbi
	NOV-2017
	Operater Overloading 
*/

#include "MySet.h"

MySet::MySet() // as default it hold's no memory and no size
{
	arr = nullptr;
	size = 0;
}
MySet::MySet(int _size, int _arr[]) // taking an array and its size
{
	if (_arr) // if the array is not empty
	{
		size = _size; // size of the array
		arr = new int[size]; // making dynamic memory of size given to store the data
		for (unsigned i = 0; i < size; i++)
			arr[i] = _arr[i];		// assigning the array with the giver array

		std::sort(arr, arr + size); // c++ bulit in sort function which sort the array from smaller to greater it takes two values starting address of array and endling address of array
	}
}
MySet::MySet(const MySet& _obj) // copy Constructor 
{
	size = _obj.size; // size of the array
	arr = new int[size];// making dynamic memory of size given to store the data
	for (unsigned i = 0; i < size; i++)
		arr[i] = _obj.arr[i];// assigning the array with the giver Objects array

	std::sort(arr, arr + size);// c++ bulit in sort function which sort the array from smaller to greater it takes two values starting address of array and endling address of array

}

MySet& MySet::operator = (const MySet& _obj) // assignment Operator
{
	if (this->size > 0) // checking if it already hold's any memory which should be deleted to avoid memory leak
		delete[]arr; // deleting previous memory

	this->size = _obj.size; // size of the array
	this->arr = new int[size]; // making dynamic memory of size given to store the data
	for (unsigned i = 0;  i < size;  i++)
		this->arr[i] = _obj.arr[i]; // assigning the array with the giver Objects array

	return *this; // return pointer to this object so that it can be used as (a = b + c + d;)
}

MySet::~MySet() // destructor
{
	size = 0; // initializing the size to zero
	delete[]arr; // deleting the memory which it holds to avoid memory leak
	arr = nullptr; // initializzing the pointer to nullptr to avoid dangling pointer
}


MySet MySet::operator + (const MySet& _obj) // addition operator / union operator
{
	MySet temp; // making a temperary variable 

	temp.size = this->size + _obj.size; // initializing the sum of both the size's

	temp.arr = new int[temp.size]; // making a dynamic array to holds the data

	for (unsigned i = 0; i < this->size; i++) // initializing from first array
		temp.arr[i] = this->arr[i];

	for (unsigned i = this->size,j = 0; i < temp.size; i++,j++) // initializing from the second array in this loop i value start from the last index of the first array so that this new array holds all the data
		temp.arr[i] = _obj.arr[j];

	std::sort(temp.arr, temp.arr + temp.size); // sorting the array to remove duplications

	for (unsigned i = 0; i < temp.size-1;) // removing duplications
	{
		if (temp.arr[i] == temp.arr[i + 1]) // checking if the next element is equal to the current
		{
			for (unsigned j = i; j < temp.size - 1; j++) // copying the data from the above index to the current to remove duplication
				temp.arr[j] = temp.arr[j + 1];
			temp.size--;
		}
		else
			i++; // it is in the else part because it will check after moving the array is new number is aslo equal to the current or not
	}
	// we are not deleting the unused memory because its static object and in the assignment operator it will use the memory efficiently
	
	return temp; // returning the tempVariable
}

bool MySet::operator == (const MySet& _obj) // Equality Operator
{
	if (this->size == _obj.size) // checking if the size of this object is equal to the given object
		return true; // return true if they are equal
	return false; // return false if they are not equal
}

bool MySet::compare(int _num) // check if the given number is already in the array/set
{
	for (unsigned i = 0; i < size;i++) // loop to check all the values
		if (arr[i] == _num) // checking if any element is equal to the given number
			return true;// return true if found

	return false;// return false if not found
}

void MySet::add(int _num) // adding a number in the set/array
{
	if (!compare(_num)) // check if the number is already in the set/array if not the 
	{
		int * temp = arr; // temp hold the address to the prevoius memory location

		arr = new int[size + 1]; // making a bigger dynamic memory to hold new number

		for (unsigned i = 0; i < size; i++) // loop to copy the previous values
			arr[i] = temp[i]; // initializing the array
		arr[size] = _num; // adding the new given number on last index
		size++; // increasing the size
		delete[]temp; // deleting the previous memory which it holds and temp is pointing to that memory
		std::sort(arr, arr + size); // sorting the array
	}
}
ostream& operator << (ostream& out, const MySet& _obj) // overriding the output operator
{
	for (unsigned i = 0; i < _obj.size; i++)//loop to print the array
	{
		out << _obj.arr[i] << endl;// printing the numbers
	}
	return out; // return the out variable to the stream to process
}

istream& operator >> (istream& in, MySet& _obj) // overriding the input operator
{
	if (_obj.size > 0) // checking if it already hold's any memory which should be deleted to avoid memory leak
		delete[]_obj.arr; // deleting previous memory

	in >> _obj.size; // taking the number of elements
	_obj.arr = new int[_obj.size]; // making dynamic memory to holds the numbers
	for (unsigned i = 0; i < _obj.size; i++)//loop to initialize the array
		in >> _obj.arr[i]; // taking input from the screen
	std::sort(_obj.arr, _obj.arr + _obj.size); // c++ bulit in sort function which sort the array from smaller to greater it takes two values starting address of array and endling address of array

	return in; // returning the in variable to the stream to process
}


void MySet::print() // printing the set/array
{
	for (unsigned i = 0; i < size; i++)//loop to print the array
	{
		cout << arr[i] << endl; // printing the numbers
	}
}