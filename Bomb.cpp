#include "Bomb.h"

// Name: Bomb() - Default Constructor
// Description: Creates a new Bomb Monkey
// Preconditions: None
// Postconditions: Can create a Bomb Monkey
Bomb::Bomb(){}
// Name: Bomb(string type, int damage, int location)
// Description: Creates a new Bomb Monkey
// Preconditions: None
// Postconditions: Can create a Bomb Monkey
Bomb::Bomb(string type, int damage, int location) : Monkey(type , damage, location){}
// Name: ~Bomb - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Bomb::~Bomb(){}
// Name: Attack
// Description: Iterates through all bloons. Hits all bloons in same location as bomb.
//              Returns total bloon health or damage (whichever is less) for earnings (money)
//              EXTRA CREDIT: Only monkey that can pop Lead Bloons.
// Preconditions: Bloons must be in same location as bomb monkey
// Postconditions: Damages each bloon and returns earnings (total pops)
int Bomb::Attack(vector<Bloon*> bloon) {
	int location = GetLocation() - 1;
	unsigned int vectorSize = bloon.size();
	int earnings = 0;
	int health = 0;

	for (int i = 0; i < vectorSize; i++) {
		if (location == GetLocation()) {
			health += bloon.at(i)->GetHealth();
			health = bloon.at(i)->Pop(1);
			cout << "bomb monkey throws a bomb!" << endl;
			earnings += 1;
		}
	}
	return health < earnings ? health : earnings;

}