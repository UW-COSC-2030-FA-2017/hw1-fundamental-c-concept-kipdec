#include <iostream>
#include <stdlib.h>
#include "collection.h"
using namespace std;

int main(){
	Collection <int> c1(2);
	Object ins(69);
	Object ink(392);
	c1.printObj();
	//cout << "Size " << c1.getSize() << endl;
	//cout << "Empty? " << c1.isEmpty() << endl;
	c1.insert(ins);
	//cout << c1.objArray;
	//cout << "Size " << c1.getSize() << endl;
	c1.printObj();
	c1.insert(ink);
	c1.printObj();
	c1.remove(ins);
	c1.printObj();
	c1.notContained(ink);
	c1.remove(ins);
	c1.printObj();
	c1.notContained(ink);
	c1.removeRandom();
	c1.printObj();
	c1.removeRandom();
	c1.printObj();
	c1.notContained(ins);
	c1.removeRandom();
	c1.removeRandom();

	c1.printObj();
	c1.makeEmpty();

	c1.printObj();

	return 0;
}