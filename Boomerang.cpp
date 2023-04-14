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

#include "Boomerang.h"

// Name: Boomerang() - Default Constructor
// Description: Creates a new Boomerang Monkey
// Preconditions: None
// Postconditions: Can create a Boomerang Monkey
Boomerang::Boomerang(){}
// Name: Boomerang(string type, int damage, int location)
// Description: Creates a new Boomerang Monkey
// Preconditions: None
// Postconditions: Can create a Boomerang Monkey
Boomerang::Boomerang(string type, int damage, int location) : Monkey(type, damage, location){}
// Name: ~Boomerang - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Boomerang::~Boomerang(){}
// Name: Attack
// Description: Iterates through all bloons. For each bloon in the same location as boomerang,
//              hits each bloon twice (once out and once back)
//              Returns total bloon health or damage (whichever is less) for earnings (money)
// Preconditions: Bloons must be in same location as Boomerang Monkey
// Postconditions: Damages each bloon and returns earnings (total pops)
int Boomerang::Attack(vector<Bloon*> bloon){
	int location = GetLocation();
	int vectorSize = bloon.size();
	int earnings = 0;
	int health = 0;

	for (unsigned int i = 0; i < vectorSize; i++) {
		if (location == GetLocation()) {
			health = bloon.at(i)->GetHealth();
			bloon.at(i)->Pop(2);
			earnings += 2;
		}
	}
	return health < earnings ? health : earnings;
}