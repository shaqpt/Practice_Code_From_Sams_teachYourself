#include <iostream>
using namespace std;

int main()
{
	cout << "How many integers do you want to enter? ";
	int numEntries = 0;
	cin >> numEntries;

	int* pointsToInt = new int[numEntries]; //dynamically allocate memory for array of integers

	cout << "Allocated for " << numEntries << " integers" << endl;
	for(int counter = 0; counter < numEntries; counter++)
	{
		cout << "Enter number " << counter << ": ";
		cin >> *(pointsToInt + counter); //store number in allocated memory
	}

	cout << "Displaying all numbers entered: " << endl;
	for (int counter = 0; counter < numEntries; counter++)
	{
		cout << *(pointsToInt++) << (counter < numEntries - 1 ? ", " : ""); //displays number and increments pointer
	}
	cout << endl;

	//return pointer to beginning
	pointsToInt -= numEntries; 
	/* IMPORTANT: reset pointer to beginning of array
	*  if you don't do this, you will lose the pointer to the beginning of the array 
	*  since it was modified in the previous loop (pointsToInt++)
	*  and you will not be able to deallocate memory properly
	*/
	
	//deallocate memory
	delete[] pointsToInt;

	return 0;
}