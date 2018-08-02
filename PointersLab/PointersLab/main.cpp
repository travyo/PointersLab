//
//  main.cpp
//  PointersLab
//
//  Created by Travis Young on 8/1/18.
//  Copyright © 2018 Travis Young. All rights reserved.
//

#include <iostream>
#include "Person.cpp"
using namespace std;



//function prototypes
void passByValue (int);  //init
void passByRef (int &);  //init - & indicates the function is expecting a reference type to be passed in
void modifyPerson (Person){}

int main(int argc, const char * argv[]) {
    
    int num1 = 3;  // create new variable and assign 3 to it
    int num2 {}; //create seperate variable for pNum to point to
    int *pNum = &num2;  //create pointer to addrss-of num2
    
    double *pDouble = new double;  //create pointer double with new keyword
    *pDouble = 20.22; //assign a value with dereference opperator
    
    *pNum = 5;  //assign value of 5 to pNum using dereference opwerator
    
    cout << "num1 memory address: " << &num1 << endl;  // get address-of using ampersand
    cout << "pNum memory address: "  << pNum << endl;  // memory address
    cout << "pNum init value is: " << *pNum  << endl;  //again using dereference operator to get value instead of memory address
    
    passByValue (num1);  //call function and modify num1 in the function
    
    cout << "You're in main, num1 is: " << num1 << endl;  //outputs unmodified num1
  
    passByRef(num2);
    
    cout << "You're in main, num1 is: "  << *pNum << endl;  //outputs modified num1
    
    //passByValue(pNum);  // doesn't work - no matching function.
    
    cout << "Value of double: " << *pDouble << endl;  //print using dereferenc operator
    
    //delete *pDouble;  // can't delete pointer
    delete pDouble;  //this does nothing
    
    cout << "Value of pDouble after deletioon (deallocation): " << *pDouble << endl;  //sill outputs value --not sure how to delete this -TODO
    
    // Class Person exercise
    
    // decalre a Person object
    Person person1;
    
    person1.name = "Travis";
    person1.age = 49;
    person1.height = 74;
    person1.weight = 190;
    
    cout << "My person is named: " << person1.name << ", is " << person1.age << " years old, " << person1.height << " inches tall and weighs " << person1.weight << " pounds."  << endl;
    
    modifyPerson(person1);
    {
        person1.name = "Sivart";
    }

    
    cout << "My person is now named: " << person1.name << ", is " << person1.age << " years old, " << person1.height << " inches tall and weighs " << person1.weight << " pounds."  << endl;
    
    return 0;
}

void passByValue (int n)
{
    n = 30; // modify
    cout << "You're in function passByValue, num1 is " << n << endl;
}

void passByRef (int &n)  // & declares an "alias' to the variable passed in
{
    
    n = 50;
    cout << "You've called passByRef, num1 is: " << n << endl;
}

