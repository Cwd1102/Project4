/*****************************************
** File:    Game.cpp
** Project: CMSC 202 Project 4, Spring 2023
** Author:  Ouwen Dai
** Date:    4/20/23
** Section: 43
** E-mail:  odai1@umbc.edu
**
**
***********************************************/

#include "Game.h"

// Name: Game() - Default Constructor
// Description: Creates a new Game and populates money, round, and health
// Preconditions: None
// Postconditions: Initializes all game variables to defaults (constants)
// including rounds played
Game::Game(){
    m_curRound = START_ROUND;
    m_curMoney = START_MONEY;
    m_curLife = START_LIFE;
}
// Name: ~Game
// Description: Destructor
// Preconditions: None
// Postconditions: Deallocates anything dynamically allocated in Game
Game::~Game(){
    
    for (unsigned int i = 0; i < m_bloons.size(); i++) {
        delete m_bloons.at(i);
    }
    for (unsigned int i = 0; i < m_monkeys.size(); i++) {
        delete m_monkeys.at(i);
    }

}
// Name: PrintMap()
// Description: For each location on the path, outputs the bloons and the monkeys (or none)
// Precondition: None
// Postcondition: None
void Game::PrintMap(){
    int numMonkeys = 0;
    int numBloons = 0;

    //loops for the length of the game
    for (int i = 0; i < PATH_LENGTH; i++) {
        cout << "**Location " << i + 1<< "**" << endl;
        cout << "--Monkeys--" << endl;

        //loops for the size of the monkey vector
        for (unsigned int j = 0; j < m_monkeys.size(); j++) {
            //checks if there are any monkeys at the i location
            if (m_monkeys.at(j)->GetLocation() - 1 == i) {
                numMonkeys++;
            }
        }
        //loops for the size of the bloon vector
        for ( unsigned int j = 0; j < m_bloons.size(); j++) {
            //checks if there are any bloons at the i location
            if (m_bloons.at(j)->GetLocation() == i) {
                numBloons++;
            }
        }

        //checks if there are any monkeys at the location
        if (numMonkeys> 0) {
            //loops for sized of monkey vector
            for (unsigned int j = 0; j < m_monkeys.size(); j++) {
                //checks if there are any monkeys at the i location
                if (i == m_monkeys.at(j)->GetLocation() - 1) {
                    cout << j + 1 << ". ";
                    cout << *m_monkeys.at(j);
                }
            }
        }
        else {
            cout << "None" << endl;
        }

        cout << "<<Bloons>>" << endl;
        //checks if there are any bloons at the location
        if (numBloons > 0) {
            //loops for sized of bloon vector
            for (unsigned int j = 0; j < m_bloons.size(); j++) {
                //checks if there are any bloons at the i location
                if (i == m_bloons.at(j)->GetLocation()) {
                    cout << *m_bloons.at(j);
                }
            }
            cout << "---------------------------" << endl;
        }
        else {
            cout << "None\n" << endl;
        }
        numMonkeys = 0;
        numBloons = 0;
    }

}
// Name: ImproveMonkey
// Description: Asks the user which monkey they would like to improve
//              Increases chosen monkey's damage by IMPROVE_VALUE above
// Precondition: Must have monkeys in m_monkeys and have enough money to pay (COST_IMPROVE)
// Postcondition: Monkey's damage is permanently improved
void Game::ImproveMonkey(){
    bool condition = true;
    int choice = 0;

    //if monkey size is > 0
    if (m_monkeys.size() > 0) {
        //if you have enough money
        if (m_curMoney >= 2) {
            do {
                cout << "Which monkey would you like to improve? (1-" << m_monkeys.size() << ")" << endl;
                //loops for monkey vector size
                for (unsigned int i = 0; i < m_monkeys.size(); i++) {
                    cout << i + 1 << ". " << *m_monkeys.at(i);
                }
                cin >> choice;

                //if choice is in range
                if ((choice >= 1) && (choice <= int(m_monkeys.size()))) {
                    choice -= 1;
                    //gets name of monkey
                    string type = m_monkeys.at(choice)->GetType();
                    //gets damage of monkey
                    int damage = m_monkeys.at(choice)->GetDamage();
                    
                    //sets damage to improved value
                    m_monkeys.at(choice)->SetDamage(IMPROVE_VALUE + damage);
                    cout << type << " in position " << choice + 1 << " improved" << endl;
                    m_curMoney -= 2;
                    condition = false;
                }
            } while (condition);
        }
        else {
            cout << "You do not have enough money to improve!" << endl;
        }
    }
    else {
        cout << "There are no monkeys to improve" << endl;
    }
}
// Name: BuyMonkey
// Description: Asks the user which monkey they would like to buy
//            Reduces m_curMoney and then calls PlaceMonkey (which creates and places new monkey)
// Precondition: Must have enough money to pay (COST_DART, COST_BOOMERANG, or COST_BOMB)
// Postcondition: Specified monkey is added a chosen location on the path
void Game::BuyMonkey(){
    int choice = -1;
    bool place = false;
    
    do {
        cout << "What type of monkey would you like to buy?" << endl;
        cout << "1. Dart Monkey" << endl;
        cout << "2. Boomerang Monkey" << endl;
        cout << "3. Bomb monkey" << endl;
        cout << "4. Cancle" << endl;
        cin >> choice;

        //goes to where player wants
        switch (choice)
        {
        case 1:
            if (m_curMoney >= COST_DART){
                place = true;
            }
            break;
        case 2:
            if (m_curMoney >= COST_BOOMERANG) {
                place = true;
            }
            break;
        case 3:
            if (m_curMoney >= COST_BOMB) {
                place = true;
            }
        default:
            break;
        }
    } while (choice < 1 || choice > 4);

    if ((choice > 1) || (choice < 4)) {
        if (place) {
            //places the monkey
            PlaceMonkey(choice);
            choice = 0;
        }
        else {
            cout << "You do not have enough money to purchase this monkey" << endl;
        }
    }
 


}
// Name: PlaceMonkey(int choice)
// Description: Based on monkey purchased in BuyMonkey, asks user where to place new monkey
//              Dynamically allocates new monkey and populates location and adds to m_monkey
// Preconditions: Successfully purchased new monkey
// Postconditions: New monkey is added to m_monkey at chosen location
void Game::PlaceMonkey(int choice){
    int monkeyPlace = -1;
    //loops while monkeyPlace is not vallid
    while ((monkeyPlace < 0) || (monkeyPlace > PATH_LENGTH)) {
        cout << "where would you like to place your monkey? (1-" << PATH_LENGTH << ")" << endl;
        cin >> monkeyPlace;
        //if monkeyPlace is in range of pathlength
        if ((monkeyPlace >= 0) && (monkeyPlace <= PATH_LENGTH)) {

            //if dart monkey is selected 
            if (choice == 1) {
                Dart* newDart = new Dart("Dart Monkey", DAMAGE_DART, monkeyPlace);
                m_monkeys.push_back(newDart);
                m_curMoney -= COST_DART;
                cout << "Dart Monkey placed at location " << monkeyPlace << endl;
            }
            //if boomerang monkey is selected 
            else if (choice == 2) {
                Boomerang* newBoom = new Boomerang("Boomerang Monkey", DAMAGE_BOOM, monkeyPlace);
                m_monkeys.push_back(newBoom);
                m_curMoney -= COST_BOOMERANG;
                cout << "Boomerang Monkey placed at location " << monkeyPlace << endl;
            }
            //if bomb monkey is selected 
            else if (choice == 3) {
                Bomb* newBomb = new Bomb("Bomb Moneky", DAMAGE_BOMB, monkeyPlace);
                m_monkeys.push_back(newBomb);
                m_curMoney -= COST_BOMB;
                cout << "Bomb Monkey placed at location " << monkeyPlace << endl;
            }
        }
    }
}
// Name: StartGame()
// Description: Welcomes the player to the game. Continually calls MainMenu until user quits
// Preconditions: None
// Postconditions: Thanks user when quitting
void Game::StartGame(){
    cout << "Welcome to UMBC Bloons!" << endl;
    int choice = -1;

    //loops untill choice 6 is returned 
    do {
        choice = MainMenu();
        switch (choice)
        {
        case 1:
            PrintMap();
            break;
        case 2:
            BuyMonkey();
            break;
        case 3:
            ImproveMonkey();
            break;
        case 4:
            PlayRound();
            break;
        case 5:
            Stats();
            break;
        case 6:
            cout << "Thank you for playing!" << endl;
        default:
            break;
        }
    } while (choice != 6);
}
// Name: MainMenu()
// Description: Checks to see if player still has life. If m_curLife <= 0, game ends with loss.
//              Display menu (View Map, Buy New Monkey, Improve Existing Monkey
//              Progress Round, Check Stats, or Quit).
//              Calls function related to user choice.
// Preconditions: None
// Postconditions: Game continues until quit or player runs out of life
int Game::MainMenu(){
    int choice = -1;
    //if the player has no lives left
    if (m_curLife > 0) {
        cout << "What would you like to do ?" << endl;
        cout << "1. View Map" << endl;
        cout << "2. Buy New Monkey" << endl;
        cout << "3. Improve Existing Monkey" << endl;
        cout << "4. Progress Round" << endl;
        cout << "5. Check Stats" << endl;
        cout << "6. Quit" << endl;
        cin >> choice;
        return choice;
    }
    else {
        cout << "Game over, you lose !" << endl;
        return 6;
    }

    return -1;
}
// Name: Stats()
// Description: Displays the information about the game
//              (current round, number of monkeys, money, and lives left)
// Preconditions: None
// Postconditions: None
void Game::Stats(){
    //prints stats
    cout << "**Current Stats**" << endl;
    cout << "Current round: " << m_curRound << endl;
    cout << "Monkeys Working: " << m_monkeys.size()  << endl;
    cout << "Current Money: " << m_curMoney << endl;
    cout << "Current Life: " << m_curLife << endl;
}
// Name: PlayRound()
// Description: Announces beginning and end of round
//              Calls PopulateBloons once then ResolveBattle once.
//              Calls RemovePopped (5 times due to erase function)
//              Calls MoveBloons once then calls CheckPath (5 times due to erase call)
//              Increments curRound
// Preconditions: None
// Postconditions: Round progresses
void Game::PlayRound(){
    cout << "Startng round " << m_curRound << "!" << endl;
    PopulateBloons();
    ResolveBattle();
    //called 5 times
    for (int i = 0; i < 5; i++) {
        RemovePopped();
    }
    MoveBloons();
    //called 5 times
    for (int i = 0; i < 5; i++) {
        CheckPath();
    }
    cout << "Round " << m_curRound << " completed!" << endl;
    m_curRound++;
}
// Name: PopulateBloons
// Description: Each round, dynamically allocated bloons added to path in position START_BLOON
//              Bloons have a minimum of 1 health.
//              For each round, the number of new bloons increases matching the round number
//              For example: Round 1 = 1 red bloon (health 1)
//              Round 2 = 1 red bloon (health 1) and 1 blue bloon (health 2)
//              Round 3 = 1 red (health 1) and 1 blue (health 2) and 1 green (health 3)
//              Round 4 = 1 red, 1 blue, 1 green, and 1 yellow (health 4) and so forth
//              Notifies user that a new bloon (with color) has appeared.
// Preconditions: Round is at least 1
// Postconditions: All new bloons populated
void Game::PopulateBloons(){
    string color = "";

    //loops for the current round num
    for (int i = 0; i < m_curRound; i++) {
        //makes new bloon at location -1 and health i+1
        Basic* newBloon = new Basic(i + 1, START_BLOON);
        m_bloons.push_back(newBloon);
        cout << "A new " << newBloon->GetColor() << " appears!" << endl;
    }
}
// Name: ResolveBattle()
// Description: Each monkey attacks the whole bloon vector.
//              For each pop, curMoney is increased.
// Preconditions: Monkeys and bloons exist
// Postconditions: Damage is dealt to bloons
void Game::ResolveBattle(){
    //tells all monkeys in the game to attack
    for (unsigned int i = 0; i < m_monkeys.size(); i++) {
        m_curMoney += EARN_POP * (m_monkeys.at(i)->Attack(m_bloons));
    }
}
// Name: RemovePopped()
// Description: Iterates through m_bloons and if health is <= 0, bloon is deallocated and
//              removed from m_bloons
//         HINT: m_bloons.erase(m_bloons.begin() + counter) will erase at location
// Preconditions: Monkeys and bloons exist
// Postconditions: Bloons are removed
void Game::RemovePopped(){
    //checks every bloon in game 
    for (unsigned int i = 0; i < m_bloons.size(); i++) {
        //if bloon health is <= 0 the delete the bloon
        if (m_bloons.at(i)->GetHealth() <= 0) {
            delete m_bloons.at(i);
            m_bloons.erase(m_bloons.begin() + i);
        }
    }
}
// Name: MoveBloons
// Description: For each bloon that still lives, it moves one location down the path
// Preconditions: Monkeys and bloons exist
// Postconditions: Bloons increment their location
void Game::MoveBloons(){
    int location = 0;
    //goes through all bloons in game
    for (unsigned int i = 0; i < m_bloons.size(); i++) {
        //moves location by 1
        location = m_bloons.at(i)->GetLocation();
        m_bloons.at(i)->SetLocation(location + 1);
    }
    cout << "The bloons moves along the path" << endl;
}
// Name: CheckPath
// Description: Iterates over m_bloons to see if location is equal to (or greater than)
//              PATH_LENGTH. If location is equal to PATH_LENGTH, causes damage to player.
//              Damage to player is one per health of bloon.
//              If 10 green bloons (health 3) hit player, player takes 30 damage
//              Bloons that hurt player are deallocated and erased from m_bloons
//              HINT: m_bloons.erase(m_bloons.begin() + counter) will erase at location
// Preconditions: Monkeys and bloons exist
// Postconditions: Bloons are removed
void Game::CheckPath(){
    //goes through all bloons in game
    for (unsigned int i = 0; i < m_bloons.size(); i++) {
        //checks if the curr location of bloon is greater than path length
        if (m_bloons.at(i)->GetLocation() >= PATH_LENGTH) {
            cout << "A bloon made it to the end of the path and you took " << m_bloons.at(i)->GetHealth() << " damage." << endl;
            //subtracts life by health of bloon
            m_curLife -= m_bloons.at(i)->GetHealth();
            //deletes bloon
            delete m_bloons.at(i);
            m_bloons.erase(m_bloons.begin() + i);
        }
    }
}