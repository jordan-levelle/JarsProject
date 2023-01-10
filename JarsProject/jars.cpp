// Jordan C. Levelle 
// CS 231 C++

// Implementation File
// Implement the absract data type jarType
// class JarType


// Edit History
// 9/22 Write user defined member functions
// 9/30 Function definitions for constructors added
// 10/02 Function definitions for constructor builds for JarType, int, char completed
// 10/18 subtract/add function redefined
// 10/28 working with pointers
// 10/29 friend function for reveal, expand JarType(getJarCount)
// 11/1 Throw, Try and Catch exception callers 

#include <iostream>
#include <stdexcept>
#include "jar.h"

using namespace std;


JarType::JarType() // Function definition for initialization constructor
{
	numUnits = 0;
	JarCount++;
	cout << "Jar is Rinsing..." << endl;
}

JarType::~JarType()
{
	JarCount--;
	cout << "Destroying Jar" << endl;
}

int JarType::getJarCount()
{
	return JarCount;
}

JarType::JarType(int n) // Function definition for integer constructor
{
	numUnits = n;
	JarCount++;
	cout << "\nPrefil jar..." << endl;
}

JarType::JarType(char c) // Function definition for character constructor
{
	cout << "\nPrefil Jar using a character..." << endl;

	if (c == 'p')
		numUnits = 16;
	else if (c == 'q')
		numUnits = 32;
	else if (c == 'a')
		numUnits = 26;
	else
	{
		cout << "\nInvalid Input" << endl;
		numUnits = 0;
		JarCount++;
	}
}

JarType::JarType(JarType &j)
{
	cout << "In Copy Constructor." << endl;
	JarCount++;
	numUnits = j.numUnits;
}



void JarType::initToEmpty()
{
	numUnits = 0;
}


void JarType::add(int n)
{
	if (n >= 0)
		numUnits += n;
	else
		throw invalid_argument("Invalid value to add");
}


void JarType::subtract(int n)
{
	if (n >= 0)
		if ((numUnits - n) > 0)
			numUnits -= n;
		else
			throw invalid_argument("Value larger than numUnuts");
	else
		throw invalid_argument("Invalid value to subtract");
}

int JarType::quantity() const
{
	return numUnits;
}

std::ostream& operator <<(std::ostream& os, const JarType& j)
{
	os << "\nThe supplied jar contains: " << j.numUnits << " units." << endl;
	return os;
}

JarType JarType::operator+(const JarType &j)
{
	JarType tmpJar;
	tmpJar.add(this->numUnits + j.numUnits);
	return tmpJar;
}

JarType::operator int()
{
	return numUnits;
}



