#pragma once
// Jordan C. Levelle 
// CS 231 C++

// Specification File
// Declare data type LabeledJar

// Edit History
// 11/03 File created. Class LabeledJar Base JarType
// 11/08 Additional constructor type string and int
// 11/10 Invoking virtual function

#include <string>
#include "jar.h"


using namespace std;

#ifndef LABELEDJAR_H 
#define LABELEDJAR_H

class LabeledJar : public JarType {
public:
	LabeledJar(); // Constructor
	~LabeledJar(); // Constructor
	LabeledJar(int n);
	LabeledJar(string lbl, int n);
	string getLabel() const;

	virtual void showInfo() const override {
		cout << "\n Item contains: " << label << endl;
	}
	

private:
	string label;

};

#endif 

