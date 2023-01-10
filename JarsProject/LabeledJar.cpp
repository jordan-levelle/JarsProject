// Jordan C. Levelle 
// CS 231 C++

// Specification File LabeledJar 

// Edit History
// 11/03 File created. Constructor/Destructor/getLabel

#include "LabeledJar.h"

LabeledJar::LabeledJar() {
	label = "Medicine";
	cout << "\nGetting labeled jar ready" << endl;
}

LabeledJar::~LabeledJar() {
	cout << "\nDestroying labeled jar" << endl;
}

LabeledJar::LabeledJar(int n) : JarType(n) {
	label = "Olives";
	cout << "\nGetting labeled jar ready" << endl;
}

LabeledJar::LabeledJar(string lbl, int n) : JarType(n) {
	label = lbl;
	cout << "\nGetting labeled jar ready" << endl;
}

string LabeledJar::getLabel() const {
	return label;
}


