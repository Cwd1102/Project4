/*****************************************
** File:    Dart.cpp
** Project: CMSC 202 Project 4, Spring 2023
** Author:  Ouwen Dai
** Date:    4/20/23
** Section: 43
** E-mail:  odai1@umbc.edu
**
**
***********************************************/

#include "Dart.h"

// Name: Dart() - Default Constructor
// Description: Creates a new Dart Monkey
// Preconditions: None
// Postconditions: Can create a Dart Monkey
Dart::Dart(){
}
// Name: Dart(string type, int damage, int location)
// Description: Creates a new Dart Monkey
// Preconditions: None
// Postconditions: Can create a Dart Monkey
Dart::Dart(string type, int damage, int location): Monkey(type, damage, location){}
// Name: ~Dart - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Dart::~Dart(){}
// Name: Attack
// Description: Iterates through all bloons. Hits first bloon in the same location as dart.
//              Returns total bloon health or damage (whichever is less) for earnings (money)
// Preconditions: Bloon must be in same location as Dart monkey
// Postconditions: Damages one bloon and returns earnings (total pops)
int Dart::Attack(vector<Bloon*> bloon){
	int location = GetLocation() - 1;
	int vectorSize = bloon.size();
	int earnings = 0;
	int health = 0;
	
	for (unsigned int i = 0; i < vectorSize; i++) {
		if (i == location) {
			health = bloon.at(i)->GetHealth();
			health = bloon.at(i)->Pop(1);
			cout << "dart monkey throws a dart!" << endl;

			earnings++;
			return health < earnings ? health : earnings;
		}
	}
	return earnings;
}