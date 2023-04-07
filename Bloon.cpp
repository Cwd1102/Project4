#include "Bloon.h"

// Name: Bloon() - Default Constructor
// Description: Abstract class - cannot directly instantiate this class
// Preconditions: None
// Postconditions: Populates variables used in child classes (may not be specifically used)
Bloon::Bloon(){}
// Name: Bloon(int health, int location) - Overloaded Constructor
// Description: Abstract class - cannot directly instantiate this class
// Preconditions: None
// Postconditions: Populates variables used in child classes
Bloon::Bloon(int health, int location){}
// Name: virtual ~Bloon - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Bloon::~Bloon(){}
// Name: GetHealth()
// Description: Returns health of bloon
// Preconditions: Bloon has health
// Postconditions: None
int Bloon::GetHealth(){
    return 0;
}
// Name: SetHealth()
// Description: Sets health of bloon
// Preconditions: None
// Postconditions: Health is set
void Bloon::SetHealth(int){}
// Name: GetLocation()
// Description: Returns location of bloon
// Preconditions: Bloon has location
// Postconditions: None
int Bloon::GetLocation(){

    return 0;
}
// Name: SetLocation()
// Description: Sets location of bloon
// Preconditions: None
// Postconditions: Location is set
void Bloon::SetLocation(int){}
// Name: Pop()
// Description: Defines popping
// Preconditions: None
// Postconditions: None (Purely virtual - must be in child classes)
int Bloon::Pop(int damage){
    return 0;
}
// Name: GetColor
// Description: Virtual
// Preconditions: None
// Postconditions: None (Purely virtual - must be in child classes)
string Bloon::GetColor(){

    return " ";
}
// Name: Overloaded <<
// Description: Prints the details of an bloon
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with output of bloon
ostream& operator<<(ostream&, Bloon&){

}
