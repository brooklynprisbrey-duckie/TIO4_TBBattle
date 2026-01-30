// Please have more than one function. At least one of them passing a value by reference :)
#include <iostream>
#include <ctime>

using namespace std;

int displayMenu(int playerHealth, int monsterHealth) {//no pointers because no change
    int playerMove = 7;
    cout << endl << "Player HP: " << playerHealth << endl;
    cout << "Monster HP: " << monsterHealth << endl;
    cout << endl;
    cout << "What is your next move?\n";
    cout << "1. Attack\n";
    cout << "2. Heal \n";
    cout << "3. Quit \n";
    cin >> playerMove;
    return playerMove;
}

int playerAttack(int& monsterHealth) {
    int attack = 0;
    attack = rand() % 21 + 1;
    cout << "You attack for " << attack << endl;
    monsterHealth = monsterHealth - attack;
    return monsterHealth;
}

int playerHeal(int& playerHealth) {
    int heal = 0;
    heal = rand() % 21 + 1;
    cout << "You heal for " << heal << endl;
    playerHealth = playerHealth + heal;
    return playerHealth;
}

int monsterAttack(int& playerHealth) {
    int attack = 0;
    attack = rand() % 21 + 1;
    cout << "The monster attacks for " << attack << endl;
    playerHealth = playerHealth - attack;
    return playerHealth;
}


bool checkHealth(int &health) {
    return (health > 0);
}

int main() {
    srand(time(0));
	int playerHP = 100;
	int monsterHP = 100;

    while (checkHealth(playerHP) && checkHealth(monsterHP)) {
        int choice = 0;
        while (choice == 0) {
            choice = displayMenu(playerHP, monsterHP);
            if (3 < choice || choice < 1) {
                cout << "Invalid choice" << endl;
                choice = 0;
            }
        }

        switch (choice) {
        case 1:
            playerAttack(monsterHP);
            break;
        case 2:
            playerHeal(playerHP);
            break;
        case 3:
            playerHP = 0;
            break; //if you quit the game you die in game life.
        default:
            break;
        }

        if (!checkHealth(monsterHP) || !checkHealth(playerHP)) {
            break;
        }

        monsterAttack(playerHP);
    }

    if (!checkHealth(monsterHP)) {
        cout << endl << "You have defeated the monster! Congratulations. You depart the dungeon in glory." << endl;
    }
    else if (!checkHealth(playerHP)) {
        cout << endl << "You leave the dungeon in an untimely and unfortunate manner. Because you died. Miserably." << endl;
    }
    else {
        cout << "You have clipped into the dungeon walls.";
    }

    return 0;
}