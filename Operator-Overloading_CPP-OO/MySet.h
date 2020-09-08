/*
	Nawaf Alharbi
	NOV-2017
	Operater Overloading 
*/

#include <iostream> // header file to use cin,cout,ostream,istream
#include <algorithm> // header file to use sort function

using namespace std;

class MySet
{
public:
	MySet(); // default Constructor 
	MySet(int,int[]);// Constructor with an array and number of elements in array
	MySet(const MySet&); // Copy Constructor
	~MySet();// default Destructor
	MySet& operator = (const MySet&); // Assignment Operator
	MySet operator + (const MySet&); // Addition/Union Operator
	bool operator == (const MySet&); // Equality Operator
	bool compare(int); // Function Used To Compare Whether a Number is in it or not
	void add(int); // insert A Number in The Array if it is not present in it
	void print(); // print function to print the array
	friend ostream& operator << (ostream& , const MySet&); // Output/Insertion operator 
	friend istream& operator >> (istream&, MySet&); // Input/Extraction  operator 

private:
	int * arr; // pointer to an integer array
	unsigned size; // number of Elements Present In the Array (its unsigned integer because size of something can't be a negative number)
};
