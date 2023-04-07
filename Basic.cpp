#include "Basic.h"

// Name: Basic() - Default Constructor
// Description: Creates a new Basic Monkey
// Preconditions: None
// Postconditions: Can create a Basic Monkey
Basic::Basic(){}
// Name: Basic(int health, int location)
// Description: Creates a new basic bloon with health at a specific location
// if health = 1, red, 2=blue, 3=green, 4=yellow, 5=pink, >=6=black
// Preconditions: None
// Postconditions: Can create a basic bloon
Basic::Basic(int, int){}
// Name: ~Basic - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Basic::~Basic(){}
// Name: Pop
// Description: Changes the color of the bloon based on how many health it has left
// red = 1, blue = 2, green = 3, yellow = 4, pink = 5, black >=6
// Preconditions: None
// Postconditions: Returns 1 if still alive, returns 0 if health <= 0
int Basic::Pop(int damage){

    return 0;
}
// Name: GetColor()
// Description: Returns the current color of a bloon
// Preconditions: None
// Postconditions: None
string Basic::GetColor(){

    return "";
}