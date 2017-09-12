//
//  parameterpassingdemo.cpp
//  
//
//  Created by Kip DeCastro on 9/12/17.
//
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void passByValue(int someVar);
void passByReference(int& someVar);

int main(){
	int ourVar;
    cout << "What do we want our integer variable to be? ";
    cin >> ourVar;
    cout << "Our variable is " << ourVar << ", now lets see what happens when " <<
    	"we pass by value..." << endl;
    passByValue(ourVar);
    cout << "Our variable is now " << ourVar << ". \nNow lets pass by reference!"
    	<< endl;
    passByReference(ourVar);
    cout << "Our variable is now " << ourVar << endl;
}

void passByValue(int someVar){
    someVar = 100;
    cout << "You just passed by value. The value is " << someVar << endl;
}

void passByReference(int& someVar){
	someVar = 200;
	cout << "You just passed by reference. The value is " << someVar << endl;
}


