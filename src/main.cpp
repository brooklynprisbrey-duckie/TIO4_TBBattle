// Please have more than one function. At least one of them passing a value by reference :)
#include <iostream>
#include <ctime>
//include many things
using namespace std;

int displayMenu(int playerHealth, int monsterHealth) {//no pointers because no change
    int playerMove = 7;
    cout << "Player HP: " << playerHealth << endl;
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
	int playerHP = 100;
	int monsterHP = 100;

    while (checkHealth(playerHP) && checkHealth(monsterHP)) {
        int choice = 0;
        while (choice == 0) {
            choice = displayMenu(playerHP, monsterHP);
            if (4 < choice || choice < 0)
                choice = 0;
        }
        playerAttack(monsterHP);
        monsterAttack(playerHP);
    }

    return 0;
}