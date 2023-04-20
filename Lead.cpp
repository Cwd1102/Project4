/*****************************************
** File:    Basic.cpp
** Project: CMSC 202 Project 4, Spring 2023
** Author:  Ouwen Dai
** Date:    4/20/23
** Section: 43
** E-mail:  odai1@umbc.edu
**
**
***********************************************/

#include "Lead.h"

// Name: Lead() - Default Constructor
// Description: Creates a new Lead Monkey
// Preconditions: None
// Postconditions: Can create a Lead Monkey
Lead::Lead(){}
// Name: Lead(int health, int location)
// Description: Creates a new Lead bloon with health at a specific location
// if health = 1, red, 2=blue, 3=green, 4=yellow, 5=pink, >=6=black
// Preconditions: None
// Postconditions: Can create a Lead bloon
Lead::Lead(int health, int location) : Bloon(health , location){}
// Name: ~Lead - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Lead::~Lead(){}
// Name: Pop
// Description: Changes the color of the bloon based on how many health it has left
// red = 1, blue = 2, green = 3, yellow = 4, pink = 5, black >=6
// Preconditions: None
// Postconditions: Returns 1 if still alive, returns 0 if health <= 0
int Lead::Pop(int damage){


}
// Name: GetColor()
// Description: Returns the current color of a bloon
// Preconditions: None
// Postconditions: None
string Lead::GetColor() {
	return m_color;
}