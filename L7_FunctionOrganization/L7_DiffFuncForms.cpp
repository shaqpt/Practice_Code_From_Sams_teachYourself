#include <iostream>
#include <array> //to use a non C-style array
#include <vector>
#include <algorithm>
using namespace std;

const double Pi = 3.14159265;

double Area(double radius); // for circle
double Area(double radius, double height); // for cylinder

void DisplayArray(int nums[], size_t length); //c-tyle array method, no predefined length
void DisplayArray(const std::array<char, 7>& chars); //non c-style array method, predefined length

void OverloadingFunctionEx();
void PassArrayEx();

void PassByRefEx();

void DisplayNums(vector<int>& dynArray);
void LambdaFuncEx();

int main()
{
	cout << "*********************************** \nStart Overloading Function Example\n" << endl;
	OverloadingFunctionEx();
	cout << endl;
	cout << "*********************************** \nStart Pass Arrays to Function Example\n" << endl;
	PassArrayEx();
	cout << endl;
	cout << "*********************************** \nStart Pass By Reference Example\n" << endl;
	PassByRefEx();
	cout << "*********************************** \nStart Lambda Function Example\n" << endl;
	LambdaFuncEx();
	cout << endl;
	return 0;
}

double Area(double radius)
{
	return Pi * radius * radius;
}

double Area(double radius, double height) //overloaded function for Cylinder calulcation
{
	return 2 * Area(radius) + 2 * Pi * radius * height;
}

void OverloadingFunctionEx()
{
	/***********************************************************************************************/
	//Start Overloading Function Example
	cout << "Enter z for Cylinder, c for Circle: ";
	char userSelection = 'z';
	cin >> userSelection;

	cout << "Enter radius: ";
	double radius = 0;
	cin >> radius;

	if (userSelection == 'z')
	{
		cout << "Enter height: ";
		double height = 0;
		cin >> height;

		//Invoke overloaded variant of Area for Cylinder
		cout << "Area of Cylinder is: " << Area(radius, height) << endl;
	}
	else
		cout << "Area of Circle is: " << Area(radius) << endl;
	//End Overloading Function Example
	/***********************************************************************************************/
}

void DisplayArray(int nums[], size_t length)
{
	for (int index = 0; index < length; index++)
		cout << nums[index] << " ";

	cout << endl;
}

void DisplayArray(const std::array<char, 7>& chars)
{
	cout << "Method 1: ";
	for (int index = 0; index < 7; index++)
		cout << chars[index] << " "; //pass the element at index within array
	cout << endl;

	//OR -- newer C++ method
	cout << "Method 2: ";
	for (char c : chars)
		cout << c << " "; //just pass the char element
	cout << endl;
}

void PassArrayEx()
{
	/***********************************************************************************************/
	//Start Pass Arrays to Function Example
	int myNums[] = { 2, 4, 6, 8, 10 }; //myNums == c-style array --> use sizeof() to determine size
	DisplayArray(myNums, sizeof(myNums) / sizeof(myNums[0])); //

	std::array<char, 7> myStatement = { 'H', 'E', 'L', 'L', 'O', '\0' }; //non-C-style Array
	DisplayArray(myStatement);

	//End Pass Arrays to Function Example
	/***********************************************************************************************/
}

void AreaByRef(double& radius, double& result)
{
	radius += 1; //with pass argument by reference, radius is actually manipulated outside of the calling function
	result = Pi * (radius - 1) * (radius - 1);
}

double AreaByReg(double radius)
{
	radius += 1; //this is a copy of radius. Radius is not affected outside of this function. Calling function won't recognize this manipulation.
	return Pi * (radius-1) * (radius-1);
}

void PassByRefEx()
{
	/***********************************************************************************************/
	//Start Pass Arguments by Reference Example
	cout << "Enter Radius: ";
	double radius = 0;
	cin >> radius;

	double areaFetched = 0;
	cout << "Result of radius without Pass by Reference: " << radius << ". Area = " << AreaByReg(radius) << endl;
	AreaByRef(radius, areaFetched);
	cout << "Result of Pass by Reference: " << "Radius = " << radius << ", areaFetched = " << areaFetched << endl;
	//End Pass Arguments by Reference Example
	/***********************************************************************************************/
}

void DisplayNums(vector<int>& dynArray)
{
	for_each(dynArray.begin(), dynArray.end(), \
		[](int Element) {cout << Element << " "; }); //Lambda Function (and inline function) to display vector elements

	cout << endl;
}

void LambdaFuncEx()
{
	/***********************************************************************************************/
	//Start Lambda Function(Anonymous Function/Lambda Expression) Example
	vector<int> myNums;
	myNums.push_back(501);
	myNums.push_back(-1);
	myNums.push_back(25);
	myNums.push_back(-35);

	cout << "Initial Vector: " << endl;
	DisplayNums(myNums);
	
	cout << "Sorting vector in descending order:" << endl;
	sort(myNums.begin(), myNums.end(), \
		[](int Num1, int Num2) {return (Num2 < Num1);} ); //Lambda Function (and inline function) used with STL algorithm (sort)
	DisplayNums(myNums);

	//Sort based on absolute values using a lambda function
	cout << "Sorting vector based on absolute value: " << endl;
	sort(myNums.begin(), myNums.end(), [](int a, int b) {
		return abs(b) < abs(a); });
	DisplayNums(myNums);
	/***********************************************************************************************/
	//End Lambda Function Example
}