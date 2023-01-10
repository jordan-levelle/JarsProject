1000#pragma once
// Jordan C. Levelle 
// CS 231 C++

// Specification File 
// Declare the abstract data type JarType

// Edit History
// 9/22 Write user defined data type: JarType
// 9/30 Constructor builds. 
// 10/02 Constructor builds and finalized. 
// 11/10 Invoking virtual function 

#ifndef JAR_H
#define JAR_H
#include <iostream>
#include <stdexcept>

using namespace std;

class JarType {
public:
	JarType(); // initialization constructor 
	~JarType();
	JarType(int n); // integer constructor 
	JarType(char c); // Character Constructor
	JarType(JarType &j); // Constructor with reference parameter j copy constructor
	JarType operator+(const JarType &j);

	void initToEmpty(); // Initialize a Jar
	void add(int n); // Add n units to the jar
	void subtract(int n); // Subtract n units from the jar
	int quantity()const; // Reveal number of units in jar

	static int getJarCount();
	friend int reveal(JarType j);
	friend std::ostream& operator<<(std::ostream& os, const JarType& j);
	operator int();

	virtual void showInfo() const {
		cout << "\n Item contains: " << numUnits << " units" << endl;
	}







private:
	int numUnits;
	static int JarCount;
};

#endif 