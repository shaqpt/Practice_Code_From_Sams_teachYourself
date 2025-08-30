/* To access Pointed data, use the dereference operator (*) */
#include <iostream>
using namespace std;

int main()
{
	int age = 30;
	int dogsAge = 9;

	cout << "Integer Age = " << age << endl;
	cout << "Integer dogsAge = " << dogsAge << endl;

	int* pointsToInt = &age;
	cout << "pointToInt points to age. \nValue of Pointer: = 0x" << hex << pointsToInt << endl; //display value of pointer
	cout << "*pointsToInt = " << dec << *pointsToInt << endl; //display value at pointed location

	pointsToInt = &dogsAge;
	cout << "pointsToInt points to dogsAge now. \npointsToInt = 0x" << hex << pointsToInt << endl;
	cout << "*pointsToInt = " << dec << *pointsToInt << endl;

	cout << "Enter a new age for your dog: ";
	cin >> *pointsToInt;

	cout << "\npointsToInt points to dogsAge now. \npointsToInt = 0x" << hex << pointsToInt << endl;
	cout << "*pointsToInt = " << dec << *pointsToInt << endl;
	cout << "Integer dogsAge = " << dogsAge << endl; //dogsAge integer is now changed here when user modifies *pointsToInt

	return 0;
}