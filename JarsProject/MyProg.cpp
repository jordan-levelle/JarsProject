 // MyProg.cpp : File contains 'main' function. 
// Jordan C. Levelle 
// CS 231 C++

// Edit History
// 09/22 J.C.L Create jars.cpp, jar.h, MyProg.cpp
// 09/22 Write main program function. 
// 09/22 Protect against negative input.
// 10/02 Constructor Builds for JarType, int, char.
// 10/03 Global function added. Asks user for the number of units.
// 10/16 Pass by referance/value edits
// 10/18 Reformat jar 3, template function, JarType shelf of 3 jars created
// 10/28 Working with pointers
// 10/29 Friend function for reveal, expand JarType(getJarCount)
// 11/01 Throw, Try, and Catch exception callers 
// 11/03 Add labeledjar "pills"

#include <iostream>
#include <iomanip>
#include <stdexcept> 
#include <memory>
#include "jar.h"
#include "LabeledJar.h"

using namespace std;

// int getInput(int & n); pass by referance ***commented out***

// int getInput(int n); pass by value ***commented out*** 

template <typename T> // Template <keyword(typename) template parameter list(T)>
int getInput(T& n);   // Prototype appears before main

int reveal(JarType j); // Function prototype freind function 'reveal'

int JarType::JarCount = 0; // Initialize jar counter

int main()
{
    cout << "Count of jars is: " << JarType::getJarCount() << endl;
    JarType jar1, jar2;
    cout << "After jar1 and jar2 the count of jars is: " << JarType::getJarCount() << endl;

    // ***Commented out*** Compilation error 
    // int numUnits is memberfunction of private
    // ***jar1.numUnits = 10000;***

    jar1.initToEmpty();
    jar2.initToEmpty();

    jar1.add(10);
    jar2 = jar1;
    jar2.add(5);
    jar2.subtract(4);

    cout << "\nJar1 contains: " << jar1.quantity();
    cout << "\nJar2 contains: " << jar2.quantity() << endl;

    JarType jar3(50);
    cout << "\nJar3 contains: " << jar3.quantity();
    
    try {
        jar3.add(-1000);
    }
    
    catch (const invalid_argument &k) {
        cout << "\nException Occured: " << k.what() << endl;
    }
    try {
        jar3.subtract(10);
        jar3.subtract(100);
        jar3.subtract(-20);
        cout << "Jar3 contains: " << jar3.quantity() << endl;
    }
    catch (const invalid_argument& k) {
        cout << "\nException Occured: " << k.what() << endl;
    }
   
    JarType jar4('p');
        cout << "\nJar4 contains: " << jar4.quantity() << endl;

    JarType jar5('q');
        cout << "\nJar5 contains: " << jar5.quantity() << endl;

    JarType jar6('s');
        cout << "\nJar6 contains: " << jar6.quantity() << endl;

    JarType jar7;
    int value = 0;
    int status = getInput(value); // Using template
        if (status == 0){
        jar7.add(value);
        }
        cout << "\nJar7 contains: " << jar7.quantity() << endl;


    cout << "A shelf of jars:" << endl;

    JarType shelf[3]; // shelf of 3 jars

    shelf[0] = jar3;
    shelf[1] = jar4;
    shelf[2] = jar5;

    for (int i = 0; i < 3; i++) // Declaring an array, using loop to initialize arrays elements
        shelf[i].add((i + 1) * 10);
    for (int i = 0; i < 3; i++)
        cout << shelf[i].quantity() << " "; 
        cout <<endl;

    JarType * jarPtr = nullptr; //Define the pointer variable
    jarPtr = &jar1; // Get Address of jar1 
        cout << "\nShowing quantities in jar1 via a pointer variable: " << jarPtr->quantity() << endl;
        cout << "\nUse of dynamically allocated rack of jars: " << endl;

    JarType* rack = new JarType[5];
        try {
            for (int i = 0; i < 5; i++)
                (*(rack + i)).add((i + 1) * 10);
            for (int i = 0; i < 5; i++)
                cout << "Rack item: " << (i + 1) << " has: " << (*(rack + i)).quantity() << endl;
            
            delete[] rack;
        }
        catch (std::bad_alloc e) {
            cout << "\nUnable to allocate memory because: " << e.what() << endl;
        }

    JarType jar20(jar1);
        cout << "\njar20 was created by a copy constructor to be an exact copy of jar1. Quanitity: " << jar20.quantity() << endl;
        cout << "According to reveal, jar20 has this many units: " << reveal(jar20) << endl;
    
    
    LabeledJar pills; // Create object "pills"

    pills.add(25);
        cout << "\nLabeled jar contains: " << pills.quantity() << "units" << endl;
        cout << "\nLabeled jar is labeled: " << pills.getLabel() << endl;

    const int arraySize = 10;
    unique_ptr< JarType[] > wareHouse(new JarType[arraySize]);

    // Add a few quantities in each jar
    for (int i = 0; i < 5; i++)
        wareHouse[i].add((i + 1) * 100);

    // Show the quantities in each item
    for (int i = 0; i < arraySize; i++)
        cout << " Item " << i << " has: " << wareHouse[i].quantity() << endl;

    // Overloading operators 
    cout << jar1;
    JarType jar30;
    jar30 = jar1 + jar2;
    cout << jar30;

    // Jar conversion to int
    int xyz = jar1;
    jar2 = xyz;
    cout <<"\nConvert Jar to type int. xyz contains: " << xyz;

    LabeledJar olives(40);
    cout << "\nThe labeled jar is labeled: " << olives.getLabel() << endl;
    cout << "\nThe Labeled jar contains: " << olives.quantity() << " units" << endl;

    LabeledJar snack("Cookies", 0);
    cout << "\nThe Labeled jar is labeled: " << snack.getLabel() << endl;
    cout << "\nThe Labeled jar contains: " << snack.quantity() << endl;

    LabeledJar candy("StarBurst", 50);
    cout << "\nThe Labeled jar is labeled: " << candy.getLabel() << endl;
    cout << "\nThe Labeled jar contains: " << candy.quantity() << " units" << endl;

    JarType* arrayOfJars[4];
    arrayOfJars[0] = &jar1;
    arrayOfJars[1] = &olives;
    arrayOfJars[2] = &jar3;
    arrayOfJars[3] = &jar2;

    for (int i = 0; i < 4; i++) {
        arrayOfJars[i]->showInfo();
    }


  


system("pause>0");
}
//end of main 

// Begin template function definitions and parameters
template <typename T>
int getInput(T& n) 
{
    T temp;

    cout << "\nPlease enter number of units:";
    cin >> temp;

    if (temp > 0)
    {
        n = temp;
        return 0;
    }
    return 1;
}

int reveal(JarType j)
{
    return j.numUnits; // Direct access to all properties of JarType
}






//Description: A function to ask user for a value
//Return status: 0 a valid number is entered
// 1 a valid number is not entered

//int getInput(int & n){
//  int temp;
//  cout << "Please enter number of units: ";
//  cin >> temp;
//  if (temp > 0){
//  n = temp;
//  return 0;
//  }
//  return 1;
//  } End of getInput()

