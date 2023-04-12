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


}
// Name: PrintMap()
// Description: For each location on the path, outputs the bloons and the monkeys (or none)
// Precondition: None
// Postcondition: None
void Game::PrintMap(){


}
// Name: ImproveMonkey
// Description: Asks the user which monkey they would like to improve
//              Increases chosen monkey's damage by IMPROVE_VALUE above
// Precondition: Must have monkeys in m_monkeys and have enough money to pay (COST_IMPROVE)
// Postcondition: Monkey's damage is permanently improved
void Game::ImproveMonkey(){

}
// Name: BuyMonkey
// Description: Asks the user which monkey they would like to buy
//            Reduces m_curMoney and then calls PlaceMonkey (which creates and places new monkey)
// Precondition: Must have enough money to pay (COST_DART, COST_BOOMERANG, or COST_BOMB)
// Postcondition: Specified monkey is added a chosen location on the path
void Game::BuyMonkey(){
}
// Name: PlaceMonkey(int choice)
// Description: Based on monkey purchased in BuyMonkey, asks user where to place new monkey
//              Dynamically allocates new monkey and populates location and adds to m_monkey
// Preconditions: Successfully purchased new monkey
// Postconditions: New monkey is added to m_monkey at chosen location
void Game::PlaceMonkey(int choice){
}
// Name: StartGame()
// Description: Welcomes the player to the game. Continually calls MainMenu until user quits
// Preconditions: None
// Postconditions: Thanks user when quitting
void Game::StartGame(){
    cout << "Welcome to UMBC Bloons!" << endl;
    int choice = -1;


    do {
        choice = MainMenu();
        switch (choice)
        {
        case 1:

        case 2:
            
        case 3:

        case 4:

        case 5:

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
    int life = m_curLife;
    int choice = -1;

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
        return 0;
    }


    return -1;
}
// Name: Stats()
// Description: Displays the information about the game
//              (current round, number of monkeys, money, and lives left)
// Preconditions: None
// Postconditions: None
void Game::Stats(){}
// Name: PlayRound()
// Description: Announces beginning and end of round
//              Calls PopulateBloons once then ResolveBattle once.
//              Calls RemovePopped (5 times due to erase function)
//              Calls MoveBloons once then calls CheckPath (5 times due to erase call)
//              Increments curRound
// Preconditions: None
// Postconditions: Round progresses
void Game::PlayRound(){}
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
void Game::PopulateBloons(){}
// Name: ResolveBattle()
// Description: Each monkey attacks the whole bloon vector.
//              For each pop, curMoney is increased.
// Preconditions: Monkeys and bloons exist
// Postconditions: Damage is dealt to bloons
void Game::ResolveBattle(){}
// Name: RemovePopped()
// Description: Iterates through m_bloons and if health is <= 0, bloon is deallocated and
//              removed from m_bloons
//         HINT: m_bloons.erase(m_bloons.begin() + counter) will erase at location
// Preconditions: Monkeys and bloons exist
// Postconditions: Bloons are removed
void Game::RemovePopped(){}
// Name: MoveBloons
// Description: For each bloon that still lives, it moves one location down the path
// Preconditions: Monkeys and bloons exist
// Postconditions: Bloons increment their location
void Game::MoveBloons(){}
// Name: CheckPath
// Description: Iterates over m_bloons to see if location is equal to (or greater than)
//              PATH_LENGTH. If location is equal to PATH_LENGTH, causes damage to player.
//              Damage to player is one per health of bloon.
//              If 10 green bloons (health 3) hit player, player takes 30 damage
//              Bloons that hurt player are deallocated and erased from m_bloons
//              HINT: m_bloons.erase(m_bloons.begin() + counter) will erase at location
// Preconditions: Monkeys and bloons exist
// Postconditions: Bloons are removed
void Game::CheckPath(){}