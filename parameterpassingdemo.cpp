//
//  parameterpassingdemo.cpp
//  This program demonstrates how parameter passing works through pass by value
//  and pass by reference.
//  Created by Kip DeCastro on 9/12/17.
//
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void passByValue(int someVar); 			// Our function to pass by value
void passByReference(int& someVar);		// Our function to pass by reference.

int main(){
	int ourVar;
    cout << "What do we want our integer variable to be? ";
    cin >> ourVar;
    cout << "Our variable is " << ourVar << ", now lets see what happens when " <<
    	"we pass by value..." << endl; 	// ourVar will not change here.
    passByValue(ourVar);
    cout << "Our variable is now " << ourVar << ". \nNow lets pass by reference!"
    	<< endl;
    passByReference(ourVar);
    cout << "Our variable is now " << ourVar << endl; // ourVar will now change.
}

void passByValue(int someVar){
    someVar = 100;
    cout << "You just passed by value. The value is " << someVar << endl;
}

void passByReference(int& someVar){
	someVar = 200;
	cout << "You just passed by reference. The value is " << someVar << endl;
}


