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
	int location = GetLocation();
	int earnings = 0;
	int health = 0;
	int currHealth = 0;
	//loops for the size of the bloon vector
	for (unsigned int i = 0; i < bloon.size(); i++) {
		//checks if the location of the monkey is the same as the location of the bloon
		if (location == bloon.at(i)->GetLocation() + 1) {
			//checks if the bloon is alive
			if (bloon.at(i)->GetHealth() > 0) {
				cout << "bomb monkey throws a bomb!" << endl;
				//adds up health before pop
				health += bloon.at(i)->GetHealth();
				currHealth = bloon.at(i)->GetHealth();
				bloon.at(i)->Pop(GetDamage());
				earnings += (currHealth - bloon.at(i)->GetHealth());
			}
		}
	}
	//if health is less than earnings, returs health, and vice versa
	return health < earnings ? health : earnings;

}