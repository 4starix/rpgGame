// CPP_RPG.cpp : Defines the entry point for the console application.
// C++ RPG game by Jack Win

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

// FOR Sleep() FUNCTION
#include <Windows.h>

struct entity 
{
	int health;
	int attack;
	string name;
};

struct playerInfo /*Struct containing all of the player's info*/
{
	int money = 0; /*Player's Money*/
	int fightAmount = 0; /*How many times the player has fought in a battle*/
	int weaponLevel = 0; /*Variable used for the shop*/
	int healthLevel = 0; /*Variable used for the shop*/
	string weapon = "Knife"; /*Player's Current Weapon*/
	int donaldDefeated = 0;
	bool secret = false;
	entity info = { 20, 5 };
	int enemyChoice;
	int attackChoice;
};

playerInfo fight(playerInfo player); /*Fight function with player info*/
playerInfo shop(playerInfo player); /*Shop function with player info*/
void secret();
void death();
playerInfo replenishHealth(playerInfo player);

int main()
{
	// INITIALIZATION
	srand(time(NULL));
	int input = 0;
	//char wait; /*Wait variable so the program waits for input to exit*/
	playerInfo player; /*The Player*/

	// INTRO
	cout << R"(  _____  _____   _____                                _       _ 
 |  __ \|  __ \ / ____|                              | |     | |
 | |__) | |__) | |  __    __ _  __ _ _ __ ___   ___  | | ___ | |
 |  _  /|  ___/| | |_ |  / _` |/ _` | '_ ` _ \ / _ \ | |/ _ \| |
 | | \ \| |    | |__| | | (_| | (_| | | | | | |  __/ | | (_) | |
 |_|  \_\_|     \_____|  \__, |\__,_|_| |_| |_|\___| |_|\___/|_|
                          __/ |                                 
                         |___/                                  )";
	cout << "\n\nWhat is your name?" << endl;
	getline(cin, player.info.name);
	if (player.info.name == "sans")
		player.money = 1000;
	cout << "\nAh, I see your parents named you of the culture of the 21st century. A wise one you may be, " << player.info.name << ".\n" << flush;
	system("pause");
	cout << "\nThe story goes as follows: get rid of 6 of your most powerful enemies, with increasing difficulty.";
	cout << "\nEnjoy the game!" << endl;
	system("pause");

	// GAME
	cout << "\nWelcome to the game! Quick tutorial, you only have to enter numbers (NO LETTERS) corresponding to your event choice.\nIn a fight, if you die, you lose.\nGood luck!\n";
	system("pause");
	do {
		if (player.info.health <= 0) {
			input = 3;
		}
		else
		{
			system("cls");
			cout << "What would you like to do?";
			cout << "\n1: Fight an enemy \n2: Visit the shop \n3: Exit the game";
			if (player.donaldDefeated == 1)
				cout << "\n4: Pingu";
			cout << "\nYour choice: ";
			cin >> input;
			if (cin.fail()) {
				cout << "\nCongrats. You broke the game by entering a letter. Please restart\n";
			}
			else
				switch (input)
				{
				case 1:
					player = fight(player);
					break;
				case 2:
					player = shop(player);
					if (player.secret == true) {
						input = 3;
						system("cls");
					}
					break;
				case 3:
					break;
				case 4: // GIVING UP ENDING
					input = 3;
					system("cls");
					Sleep(1000);
					cout << "As you prepare to fight Pingu, you realize one thing.";
					Sleep(2500);
					cout << "\n\nDeath";
					Sleep(2000);
					cout << "\nis imminent.";
					Sleep(5000);
					system("cls");
					cout << "You have no choice.";
					Sleep(2000);
					cout << "\n\nYou must give up.";
					Sleep(2000);
					system("cls");
					break;
				default:
					cout << "\nNot a choice.\n";
					system("pause");
					break;
				}
		}
	} while (input != 3);
	if (player.info.health < 1) { death(); cout << "You died!"; player.info.health = 0; }
	cout << "\n\nThank you for playing!" << endl << "\nYour name: " << player.info.name << "\nYour weapon: " << player.weapon << "\nYour attack: " << player.info.attack << "\nYour health: " << player.info.health << "\nYour money: " << player.money << "\nNumber of fights won: " << player.fightAmount << "\n\n";
	system("pause");
	if (player.secret == true)
		secret();
	return 0;
}

playerInfo shop(playerInfo player) {
	int purchaseChoice;
	do {
	system("cls");
	cout << "Welcome to the shop! What would you like to buy?" << endl;
	if (player.weaponLevel < 1) {
		cout << "\n1: $5 Tiny Hammer (Base Damage - 7)";
	}
	else
		cout << "\n";
	if (player.weaponLevel < 2) {
		cout << "\n2: $10 Axe (Base Damage - 8)";
	}
	else
		cout << "\n";
	if (player.weaponLevel < 3) {
		cout << "\n3: $25 Nunchucks (Base Damage - 9)";
	}
	else
		cout << "\n";
	if (player.weaponLevel < 4) {
		cout << "\n4: $50 Halberd (Base Damage - 10)";
	}
	else
		cout << "\n";
	if (player.weaponLevel < 5) {
		cout << "\n5: $100 Great Sword (Base Damage - 25)";
	}
	else
		cout << "\n";
	if (player.healthLevel < 1) {
		cout << "\n6: $5 +5 Health (25)";
	}
	else
		cout << "\n";
	if (player.healthLevel < 2) {
		cout << "\n7: $15 +10 Health (30)";
	}
	else
		cout << "\n";
	if (player.healthLevel < 3) {
		cout << "\n8: $25 +15 Health (35)";
	}
	else
		cout << "\n";
	if (player.healthLevel < 4) {
		cout << "\n9: $50 +20 Health (40)";
	}
	else
		cout << "\n";
	if (player.healthLevel < 5) {
		cout << "\n0: $100 +30 Health (50)";
	}
	else
		cout << "\n";
	cout << "\n10: Exit shop" << endl;
	cout << "\n69: $???? Secret";

		cout << "\n\nYour funds: " << player.money;
		cout << "\nWhat would you like to buy: ";
		cin >> purchaseChoice;
		switch (purchaseChoice)
		{
		case 1:
			if (player.money >= 5) {
				cout << "\nWeapon bought!";
				player.weapon = "Tiny Hammer";
				player.info.attack = 7;
				player.money -= 5;
				player.weaponLevel = 1;
				cout << "\n";
				system("pause");
			}
			else
				cout << "\nNot enough funds!";
			break;
		case 2:
			if (player.money >= 10) {
				cout << "\nWeapon bought!";
				player.weapon = "Axe";
				player.info.attack = 8;
				player.money -= 10;
				player.weaponLevel = 2;
				cout << "\n";
				system("pause");
			}
			else
				cout << "\nNot enough funds!";
			break;
		case 3:
			if (player.money >= 25) {
				cout << "\nWeapon bought!";
				player.weapon = "Nunchucks";
				player.info.attack = 9;
				player.money -= 25;
				player.weaponLevel = 3;
				cout << "\n";
				system("pause");
			}
			else
				cout << "\nNot enough funds!";
			break;
		case 4:
			if (player.money >= 50) {
				cout << "\nWeapon bought!";
				player.weapon = "Halberd";
				player.info.attack = 10;
				player.money -= 50;
				player.weaponLevel = 4;
				cout << "\n";
				system("pause");
			}
			else
				cout << "\nNot enough funds!";
			break;
		case 5:
			if (player.money >= 100) {
				cout << "\nWeapon bought!";
				player.weapon = "Great Sword";
				player.info.attack = 25;
				player.money -= 100;
				player.weaponLevel = 5;
				cout << "\n";
				system("pause");
			}
			else
				cout << "\nNot enough funds!";
			break;
		case 6:
			if (player.money >= 5) {
				cout << "\nHealth Upgrade bought!";
				player.info.health = 25;
				player.money -= 5;
				player.healthLevel = 1;
				cout << "\n";
				system("pause");
			}
			else
				cout << "\nNot enough funds!";
			break;
		case 7:
			if (player.money >= 15) {
				cout << "\nHealth Upgrade bought!";
				player.info.health = 30;
				player.money -= 15;
				player.healthLevel = 2;
				cout << "\n";
				system("pause");
			}
			else
				cout << "\nNot enough funds!";
			break;
		case 8:
			if (player.money >= 25) {
				cout << "\nHealth Upgrade bought!";
				player.info.health = 35;
				player.money -= 25;
				player.healthLevel = 3;
				cout << "\n";
				system("pause");
			}
			else
				cout << "\nNot enough funds!";
			break;
		case 9:
			if (player.money >= 50) {
				cout << "\nHealth Upgrade bought!";
				player.info.health = 40;
				player.money -= 50;
				player.healthLevel = 4;
				cout << "\n";
				system("pause");
			}
			else
				cout << "\nNot enough funds!";
			break;
		case 0:
			if (player.money >= 100) {
				cout << "\nHealth Upgrade bought!";
				player.info.health = 50;
				player.money -= 100;
				player.healthLevel = 5;
				cout << "\n";
				system("pause");
			}
			else
				cout << "\nNot enough funds!";
			break;
		case 10:
			cout << "\nExiting the shop!\n";
			system("pause");
			return player;
		case 69:
			if (player.money >= 1000) {
				player.secret = true;
				player.money -= 1000;
				cout << "\nSecret purchased! Please exit the shop.";
				cout << "\n";
				system("pause");
			}
			else
				cout << "\nNot enough funds!";
			break;
		default:
			cout << "\nNot an option";
			break;
		}
	} while (purchaseChoice != 10);
	return player;
}

playerInfo fight(playerInfo player) {
	// FIGHT FUNCTION
	entity enemies[6] = { { 10, 1, "Elmer Fudd" },{ 15, 2, "Wile E. Coyote" },{ 20, 3, "The Joker" },{ 25, 4, "Thanos" },{ 30, 5, "Donald Trump" },{ 50, 10, "Pingu" } };
	// STRENGTHS - Shotgun, Acne products, Drugs, Infinity Gaunlet, Tariffs, Immortality
	// WEAKNESSES - BIG CHUNGUS, Speed, Society, nanobots, Democrats, [IVURTKVU] (Cinquante avril)
	//sleep_for(7.5s);
	system("cls");
	cout << "Who would you like to fight?";
	for (int i = 0; i < 6; i++) {
		cout << "\n" << i + 1 << ": " << enemies[i].name;
	}
	cout << "\nYour choice: ";
	cin >> player.enemyChoice;
	if (cin.fail())
		cout << "\nCongrats. You broke the game. Restart to play again.";
	switch (player.enemyChoice) {
	case 1:
		// ELMER FUDD
		cout << "\nA wild " << enemies[player.enemyChoice - 1].name << " appears!" << endl;
		do {
			cout << "\n\n";
			system("pause");
			system("cls");
			cout << "Your Health: " << player.info.health;
			cout << "\n\n" << enemies[player.enemyChoice - 1].name << "'s Health: " << enemies[player.enemyChoice - 1].health;
			cout << "\n\nChoose your attack:";
			cout << "\n1: Use your weapon";
			cout << "\n2: Send out the BIG CHUNGUS";
			cout << "\n3: Use a shotgun";
			cout << "\nYour attack: ";
			cin >> player.attackChoice;
			switch (player.attackChoice)
			{
			case 1:
				cout << "\nYou use your " << player.weapon << " and deal " << player.info.attack << " damage.";
				enemies[player.enemyChoice - 1].health -= player.info.attack;
				break;
			case 2:
				cout << "\nYou send out the BIG CHUNGUS. It's super effective! You deal " << player.info.attack * 2 << " damage!";
				enemies[player.enemyChoice - 1].health -= player.info.attack * 2;
				break;
			case 3:
				cout << "\nYou use a shotgun against Elmer Fudd, the best shotgunner in town. It's highly uneffective. You deal " << player.info.attack / 2 << " damage.";
				enemies[player.enemyChoice - 1].health -= player.info.attack / 2;
				break;
			default:
				cout << "\nPlease choose a valid attack";
				continue;
			}
			player.info.health -= enemies[player.enemyChoice - 1].attack;
			if (player.info.health < 1)
				return player;
			cout << "\n\n" << enemies[player.enemyChoice - 1].name << " deals " << enemies[player.enemyChoice - 1].attack << " damage.";
		} while (player.info.health > 0 && enemies[player.enemyChoice - 1].health > 0);
		player.money += 5;
		cout << "\n\nYou defeated " << enemies[player.enemyChoice - 1].name << "!";
		cout << "\nYou gained 5 coins. You now have " << player.money << "." << endl;
		player = replenishHealth(player);
		system("pause");
		break;
	case 2:
		// WILE E COYOTE
		cout << "\nA wild " << enemies[player.enemyChoice - 1].name << " appears!" << endl;
		do {
			cout << "\n\n";
			system("pause");
			system("cls");
			cout << "Your Health: " << player.info.health;
			cout << "\n\n" << enemies[player.enemyChoice - 1].name << "'s Health: " << enemies[player.enemyChoice - 1].health;
			cout << "\n\nChoose your attack:";
			cout << "\n1: Use your weapon";
			cout << "\n2: Outrun him";
			cout << "\n3: Use the most popular acne product";
			cout << "\nYour attack: ";
			cin >> player.attackChoice;
			switch (player.attackChoice)
			{
			case 1:
				cout << "\nYou use your " << player.weapon << " and deal " << player.info.attack << " damage.";
				enemies[player.enemyChoice - 1].health -= player.info.attack;
				break;
			case 2:
				cout << "\nYou outrun Wile E. Coyote as he is no match for you. Stopping in front of a cliff, he falls and takes " << player.info.attack * 2 << " damage.";
				enemies[player.enemyChoice - 1].health -= player.info.attack * 2;
				break;
			case 3:
				cout << "You use the best acne products against him. However, it only makes him smoother and unable to catch. You only deal " << player.info.attack / 2 << " damage";
				enemies[player.enemyChoice - 1].health -= player.info.attack / 2;
				break;
			default:
				cout << "\nPlease choose a valid attack";
				continue;
			}
			player.info.health -= enemies[player.enemyChoice - 1].attack;
			if (player.info.health < 1)
				return player;
			cout << "\n\n" << enemies[player.enemyChoice - 1].name<< " deals " << enemies[player.enemyChoice - 1].attack << " damage.";
		} while (player.info.health > 0 && enemies[player.enemyChoice - 1].health > 0);
		player.money += 10;
		cout << "\n\nYou defeated " << enemies[player.enemyChoice - 1].name<< "!";
		cout << "\nYou gained 10 coins. You now have " << player.money << "." << endl;
		player = replenishHealth(player);
		system("pause");
		break;
	case 3:
		// THE JOKER
		cout << "\nA wild " << enemies[player.enemyChoice - 1].name<< " appears!" << endl;
		do {
			cout << "\n\n";
			system("pause");
			system("cls");
			cout << "Your Health: " << player.info.health;
			cout << "\n\n" << enemies[player.enemyChoice - 1].name<< "'s Health: " << enemies[player.enemyChoice - 1].health;
			cout << "\n\nChoose your attack:";
			cout << "\n1: Use your weapon";
			cout << "\n2: Put him in society";
			cout << "\n3: Give him drugs";
			cout << "\nYour attack: ";
			cin >> player.attackChoice;
			switch (player.attackChoice)
			{
			case 1:
				cout << "\nYou use your " << player.weapon << " and deal " << player.info.attack << " damage.";
				enemies[player.enemyChoice - 1].health -= player.info.attack;
				break;
			case 2:
				cout << "\nSociety is a terrible place to put the Joker in society. You deal "<< player.info.attack * 2 << " damage.";
				enemies[player.enemyChoice - 1].health -= player.info.attack * 2;
				break;
			case 3:
				cout << "\nGive the Joker drugs? Bad idea. He strengthens up and only takes " << player.info.attack << " damage.";
				enemies[player.enemyChoice - 1].health -= player.info.attack / 2;
				break;
			default:
				cout << "\nPlease choose a valid attack";
				continue;
			}
			player.info.health -= enemies[player.enemyChoice - 1].attack;
			if (player.info.health < 1)
				return player;
			cout << "\n\n" << enemies[player.enemyChoice - 1].name<< " deals " << enemies[player.enemyChoice - 1].attack << " damage.";
		} while (player.info.health > 0 && enemies[player.enemyChoice - 1].health > 0);
		player.money += 15;
		cout << "\n\nYou defeated " << enemies[player.enemyChoice - 1].name<< "!";
		cout << "\nYou gained 15 coins. You now have " << player.money << "." << endl;
		player = replenishHealth(player);
		system("pause");
		break;
	case 4:
		// THANOS
		cout << "\nA wild " << enemies[player.enemyChoice - 1].name<< " appears!" << endl;
		do {
			cout << "\n\n";
			system("pause");
			system("cls");
			cout << "Your Health: " << player.info.health;
			cout << "\n\n" << enemies[player.enemyChoice - 1].name<< "'s Health: " << enemies[player.enemyChoice - 1].health;
			cout << "\n\nChoose your attack:";
			cout << "\n1: Use your weapon";
			cout << "\n2: Use the Mark 85 Iron Man armor";
			cout << "\n3: Use the Infinity Gaunlet against him";
			cout << "\nYour attack: ";
			cin >> player.attackChoice;
			switch (player.attackChoice)
			{
			case 1:
				cout << "\nYou use your " << player.weapon << " and deal " << player.info.attack << " damage.";
				enemies[player.enemyChoice - 1].health -= player.info.attack;
				break;
			case 2:
				cout << "\nUsing the Mark 85 Iron Man armor, it can take the full force of the Infinity Stones and you snap your fingers, dealing " << player.info.attack * 2 << " damage.";
				enemies[player.enemyChoice - 1].health -= player.info.attack * 2;
				break;
			case 3:
				cout << "\nUnfortunately, you are unable to use the gaunlet against Thanos, as you can't get the gauntlet off his hand. You only deal " << player.info.attack << " damage.";
				enemies[player.enemyChoice - 1].health -= player.info.attack / 2;
				break;
			default:
				cout << "\nPlease choose a valid attack";
				continue;
			}
			player.info.health -= enemies[player.enemyChoice - 1].attack;
			if (player.info.health < 1)
				return player;
			cout << "\n\n" << enemies[player.enemyChoice - 1].name<< " deals " << enemies[player.enemyChoice - 1].attack << " damage.";
		} while (player.info.health > 0 && enemies[player.enemyChoice - 1].health > 0);
		player.money += 20;
		cout << "\n\nYou defeated " << enemies[player.enemyChoice - 1].name<< "!";
		cout << "\nYou gained 20 coins. You now have " << player.money << "." << endl;
		player = replenishHealth(player);
		system("pause");
		break;
	case 5:
		// DONALD TRUMP
		cout << "\nA wild " << enemies[player.enemyChoice - 1].name<< " appears!" << endl;
		do {
			cout << "\n\n";
			system("pause");
			system("cls");
			cout << "Your Health: " << player.info.health;
			cout << "\n\n" << enemies[player.enemyChoice - 1].name<< "'s Health: " << enemies[player.enemyChoice - 1].health;
			cout << "\n\nChoose your attack:";
			cout << "\n1: Use your weapon";
			cout << "\n2: Impose tariffs on him";
			cout << "\n3: Send in the Democrats";
			cout << "\nYour attack: ";
			cin >> player.attackChoice;
			switch (player.attackChoice)
			{
			case 1:
				cout << "\nYou use your " << player.weapon << " and deal " << player.info.attack << " damage.";
				enemies[player.enemyChoice - 1].health -= player.info.attack;
				break;
			case 2:
				cout << "\nYou can't put taxes on Trump, he'll just put them back on you. Trump takes " << player.info.attack / 2 << " damage.";
				enemies[player.enemyChoice - 1].health -= player.info.attack / 2;
				break;
			case 3:
				cout << "\nTrump is afraid of the Democrats! He takes " << player.info.attack * 2 << " damage.";
				enemies[player.enemyChoice - 1].health -= player.info.attack * 2;
				break;
			default:
				cout << "\nPlease choose a valid attack";
				continue;
			}
			player.info.health -= enemies[player.enemyChoice - 1].attack;
			if (player.info.health < 1)
				return player;
			cout << "\n\n" << enemies[player.enemyChoice - 1].name<< " deals " << enemies[player.enemyChoice - 1].attack << " damage.";
		} while (player.info.health > 0 && enemies[player.enemyChoice - 1].health > 0);
		player.money += 25;
		cout << "\n\nYou defeated " << enemies[player.enemyChoice - 1].name<< "!";
		cout << "\nYou gained 25 coins. You now have " << player.money << "." << endl;
		player = replenishHealth(player);
		system("pause");
		break;
	case 6:
		// PINGU
		cout << "\nA wild " << enemies[player.enemyChoice - 1].name<< " appears!" << endl;
		do {
			cout << "\n\n";
			system("pause");
			system("cls");
			cout << "Your Health: " << player.info.health;
			cout << "\n\n" << enemies[player.enemyChoice - 1].name<< "'s Health: " << enemies[player.enemyChoice - 1].health;
			cout << "\n\nChoose your attack:";
			cout << "\n1: Use your weapon";
			cout << "\n2: Make the day April 15, 2020";
			cout << "\n3: Use a special power";
			cout << "\nYour attack: ";
			cin >> player.attackChoice;
			switch (player.attackChoice)
			{
			case 1:
				cout << "\nYou use your " << player.weapon << " and deal " << player.info.attack << " damage.";
				enemies[player.enemyChoice - 1].health -= player.info.attack;
				break;
			case 2:
				cout << "\nChanging the day to April 15, 2020, you make Pingu pay his taxes. He can't handle numbers and takes " << player.info.attack * 2 << " damage.";
				enemies[player.enemyChoice - 1].health -= player.info.attack * 2;
				break;
			case 3:
				cout << "\nFoolish mortal. Pingu the almight god is somewhat immune to 'special' attacks. He only takes " << player.info.attack / 2 << " damage.";
				enemies[player.enemyChoice - 1].health -= player.info.attack / 2;
				break;
			default:
				cout << "\nPlease choose a valid attack";
				continue;
			}
			player.info.health -= enemies[player.enemyChoice - 1].attack;
			if (player.info.health < 1)
				return player;
			cout << "\n\n" << enemies[player.enemyChoice - 1].name<< " deals " << enemies[player.enemyChoice - 1].attack << " damage.";
		} while (player.info.health > 0 && enemies[player.enemyChoice - 1].health > 0);
		player.money += 50;
		cout << "\n\nYou defeated " << enemies[player.enemyChoice - 1].name<< "!";
		cout << "\nYou gained 50 coins. You now have " << player.money << "." << endl;
		player = replenishHealth(player);
		system("pause");
		break;
	default:
		cout << "\nYou only have 6 enemies, please try again." << endl;
		system("pause");
		player = fight(player);
		break;
	}
	player.fightAmount++;
	return player;
}

playerInfo replenishHealth(playerInfo player) {
	switch (player.healthLevel)
	{
	case 0:
		player.info.health = 20;
		break;
	case 1:
		player.info.health = 25;
		break;
	case 2:
		player.info.health = 30;
		break;
	case 3:
		player.info.health = 35;
		break;
	case 4:
		player.info.health = 40;
		break;
	case 5:
		player.info.health = 50;
		break;
	default:
		break;
	}
	return player;
}

void secret() {
	system("cls");
	int x = 0;
	while (x == 0) {
		system("cls");
		cout << R"(
       SANS SANS SANS SANS SANS SANS
   SANS SANS SANS SANS SANS SANS SANS SANS
   SANS SANS SANS SANS SANS SANS SANS SANS
 SANS SANS SANS SANS SANS SANS SANS SANS SANS
 SANS SANS SANS SANS SANS SANS SANS SANS SANS
SANS SANS SANS SANS SANS SANS            SANS
SANS SANS SANS SANS SANS SANS            SANS
SANS SANS SANS SANS SANS SANS            SANS
SANS           SANS      SANS            SANS
SANS SANS SANS SANS      SANS SANS SANS SANS
   SANS SANS SANS          SANS SANS SANS
   SANS   SANS SANS SANS SANS SANS   SANS
SANS SA                             NS SANS
SANS SANS   SA   NS   SA   NS   SANS SANS
       SANS                     SANS
       SANS SANS SANS SANS SANS SANS
)";
		Sleep(1000);
		system("cls");
		cout << R"(
       SANS SANS SANS SANS SANS SANS
   SANS SANS SANS SANS SANS SANS SANS SANS
   SANS SANS SANS SANS SANS SANS SANS SANS
 SANS SANS SANS SANS SANS SANS SANS SANS SANS
 SANS SANS SANS SANS SANS SANS SANS SANS SANS
SANS           SANS SANS SANS            SANS
SANS           SANS SANS SANS            SANS
SANS           SANS SANS SANS            SANS
SANS           SANS      SANS            SANS
SANS SANS SANS SANS      SANS SANS SANS SANS
   SANS SANS SANS          SANS SANS SANS
   SANS   SANS SANS SANS SANS SANS   SANS
SANS SA                             NS SANS
SANS SANS   SA   NS   SA   NS   SANS SANS
       SANS                     SANS
       SANS SANS SANS SANS SANS SANS
)";
		Sleep(1000);
	}
}

void death() {
	system("cls");
	cout << R"(

             ___  ___
            /   \/   \
            |        |
            |        |
             \      /
              \    /
               \__/


)";
	Sleep(500);
	system("cls");
	cout << R"(

           ___      ___
          /   \    /   \
          |   /   /    |
          |   \   \    |
           \  /   /   /
            \ \   \  /
             \|    |/


)";
	Sleep(1000);
	system("cls");
	cout << R"(
           ___     ___
          /___\   /___\
          ____     ___
         |   /    /   |
         |___\    \___|
          ___      ___
         \  /     /  /
          \_\     \_/
            __    __
            \|    |/
)";
	Sleep(50);
	system("cls");
	cout << R"(
           __       __
          /__\     /__\
          ___       __
         |  /      /  |
         |__\      \__|
          __        __
         \ /       / /
          \\       \/


)";
	Sleep(50);
	system("cls");
	cout << R"(
           _        _
          /_\      /_\
          __        _
         | /       / |
         |_\       \_|
         _           _
         \/         //
          \         /


)";
	Sleep(50);
	system("cls");
	cout << R"(

          /\       /\
          _         _
         |/        /|
         |\        \|
         _          _
         /          /



)";
	Sleep(50);
	system("cls");
	cout << R"(

          \        /
          _         _
         |          |
         |          |
         _          _




)";
	Sleep(50);
	system("cls");
	cout << R"(










)";
	Sleep(250);
	system("cls");
}