#include <iostream>
#include <stdlib.h>

using namespace std;

class Object {
	int num = 1337;

public:
	Object(){
		num = 1337;
	}
	Object(int x){
		num = x;
	}
	~Object(){};
	void setNum(int n){
		num = n;
	}
	int getNum(){
		return num;
	}
};

template <class T> 
class Collection {
	int numObj;
	Object* objArray = new Object[numObj];
public:
	Collection(){
		numObj = 1;
		for(int i = 0; i <= numObj; i++){
			objArray[i] = Object();
		}
	}

	Collection(int x){
		numObj = x;
		for(int i = 0; i <= numObj; i++){
			objArray[i] = Object();
		}
	}

	int getSize(){
		return numObj;
	}

	

	void insert(Object x){
		// Copy existing collection into new collection with size +1.
		// Add new object.
		cout << "Adding object..." << endl;
		int newNum = numObj + 1;
		Object *copy = new Object[newNum];

		for(int i = 0; i <= newNum; i++){
			copy[i] = objArray[i];
		}

		copy[numObj] = x;
		makeEmpty();
		numObj = newNum;
		objArray = copy;

		//delete [] copy;

		//copy = NULL;

		cout << "Value of inserted object " << objArray[numObj -1].getNum() << endl;
	}

	void remove(Object x){
		if(numObj < 0){
			cout << "There are no more objects to remove..." << endl;
		} else {
		cout << "Removing object of value " << x.getNum() << "..." 
			<< endl;
		int newNum = numObj - 1;
		Object* copy = new Object[newNum];
		bool sw = 0;
		for(int i = 0; i < numObj; i++){
			if(objArray[i].getNum() == x.getNum() && sw != 1){
				sw = 1;
				copy[i] = objArray[i + 1];
				cout << "Object successfully removed!" << endl;
			} else if(sw == 0){
				copy[i] = objArray[i];

			} else {
				copy[i] = objArray[i + 1];
			}
			if(sw != 1){
				cout << "Unable to find an object of that value.";
			}
		}

		makeEmpty();
		numObj = newNum;
		objArray = copy;
	    }

	}


	void removeRandom(){
		// Randomly removes an object from the collection.
		cout << numObj;
		if(numObj <= 0){
			cout << "There are no remaining objects to remove.";
		} else {
			cout << "Removing random object." << endl;
			srand(time(NULL));
			int rando = rand() % getSize();
			Object randObj = objArray[rando];
			cout << "Random object's value is " << objArray[rando].getNum() << endl;
			remove(randObj);
	    }	

	}


	bool notContained(Object x){
		int tf = 0;
		for(int i = 0; i < getSize(); i++){
			if(objArray[i].getNum() == x.getNum()){
				tf = 1;
				cout << "The object of value " << x.getNum() << " is contained "
					<< "within the collection." << endl; 
			}
		}
		if(tf != 1){
			cout << "The object of value " << x.getNum() << " is not contained "
				<< "within the collection." << endl;
		}
		return tf;
	}

	bool isEmpty(){
		int tf = 0;
		if(!(numObj > 0)){
			tf = 1;
		}

		return tf;
	}

	void makeEmpty(){
		// Removes all objects from the collection
		cout << "Emptying Collection...\n";
		delete [] objArray;
		numObj = 0;
		//objArray = NULL;
		cout << "Collection emptied..." << endl; 
	}

	void printObj(){
		cout << endl << "Printing Objects in Collection..." << endl;
		if((numObj >= 0)){
		for(int i = 0; i < numObj; i++){
			cout << "Object " << i << " value: " << objArray[i].getNum() << 
				endl;
		}
		cout << "Collection size : " << getSize();}
		cout << "\tIs Empty: " << isEmpty() << endl << endl;
	}


};

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