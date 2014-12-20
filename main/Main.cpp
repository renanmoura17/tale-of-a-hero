#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int TAM = 40;
const char KINGDOM[TAM] = "Plusplus Land";

char warriorName[TAM];
char enemyName[TAM];

int choice;
int assholePoints = 0;
int awesomePoints = 0;
int warriorHP = 100;
int enemyHP = 90;
int warriorGold = 0;

bool isWarriorDead = false;
bool girlIsRaped = false;

void setWarriorName() {

	cin.get(warriorName, TAM);

	while(warriorName[0] == '\n') {
		cout << "Are you kidding with the Master? State thy fucking name correctly. Do not try to skip the history";
		cin >> warriorName;
	}
}

void gameOver() {
	system("cls");
	cout << "Actually, you do not seem to be so powerful as I thought, huh?\n Poor " << warriorName << "...\n\n GAME OVER.";
}

void validateChoice() {

	while (choice != 1 && choice != 2) {
		cout << "SELECT A DAMN FUCKING VALID CHOICE, MOTHERFUCKER. DO. NOT. MESS. WITH. THE. HISTORY.\n\n";
		cin >> choice;
	}
}

void validateBattleAction(int action) {
	while (action != 1 && action != 2 && action != 3 && action != 4) {
		cout << "SELECT A DAMN FUCKING VALID ACTION, MOTHERFUCKER. DO. NOT. MESS. WITH. THE. HISTORY.\n\n";
		cin >> action;
	}
}

void forestLadyEncounter() {
	cout << "You ran in the forest, trying to track down the screams' source and ended up in a clearing, with a lake in it.\n\n";
	cout << "In the clearing, there was a young and beautiful blonde lady staring, with a desperate expression, at the lake. Apparently, she noticed you and rose almost instantly.\n";
	cout << "She has a scared look and does not say anything.\n\n";
	cout << "What are you gonna do?\n";
	cout << "1 - Rape her.\n";
	cout << "2 - Approach the girl\n";
	cin >> choice;

	validateChoice();

	system("cls");

	if (choice == 1) {
		assholePoints++;
		girlIsRaped = true;
		cout << "You quickly grabbed her and violated the poor girl. You are really an asshole.\n";
		cout << "After letting the raped lady naked, crying and impotent at the clearing, you just went back on your way home\n\n";
	}
	else if (choice == 2) {

		cout << "While making your first step, the lady just startled herself and put her hand in her pocket.\n";
		cout << "1 - Approach slowly\n";
		cout << "2 - 'Calm down. I am not going to harm you. What happened? Were you the one who screamed?'\n";
		cin >> choice;

		validateChoice();

		system("cls");

		if (choice == 1) {
			cout << "As you approached slowly, the girl suddenly screams again, drawing a sickle covered in blood. She runs at you, as you stand there astonished.\n";
			cout << "The girl jumps at your neck, slashing it from side to side.\n\n";

			system("pause");
			system("cls");

			cout << warriorName << ", you are dead.\n\n";
			isWarriorDead = true;

			system("pause");
		}
		else {
			cout << "She seemed to calm a little.\n\nLittle by little, she started to tell her history:\n\n";
			cout << "'I came here to harvest some herbs... When I got distracted collecting them, someone just tried to attack me!! I was panicked, so...\n";
			cout << "I drew the sickle I brought with me... and... and...'\n\nShe started to cry\n\n'...stabbed the attacker in his belly and pushed him onto the lake.'\n\nShe cried more intensely.\n\n";
			cout << "1 - 'It's okay. Nothing more will happen to you.\nNow, you must go back to the city, to your home, and reassure yourself. I came back from there just now. The road is safe for journey.\n";
			cout << "2 - 'You're safe now. Go back to the city.'\n";
			cin >> choice;

			validateChoice();

			system("cls");

			if (choice == 1) {
				awesomePoints++;
				cout << "'...Thank you. I feel better now. I shall be going... Thank you again, noble warrior.'\n\n";
				cout << "Wow. Such a gallant one, eh?\n\n";
			} 
			else {
				cout << "Y-yes... Thank you, warrior. I.. I must go.\n\n";
			}
		}
	}
	system("pause");
}

int battleMenu() {

	int battleAction;

	cout << "\n\n" << warriorName << "'s HP: " << warriorHP << "\n";
	cout << enemyName << "'s HP: " << enemyHP << "\n\n";

	cout << "What are you going to do?\n";
	cout << "1 - Sword attack\n";
	cout << "2 - Defend\n";
	cout << "3 - Scream like a little bitch\n";
	cout << "4 - Run\n";
	cin >> battleAction;

	validateBattleAction(battleAction);

	return battleAction;

}

void battle() {

	int action;
	int swordDamage;
	int enemyDamage;

	bool isDefending = false;

	while (warriorHP > 0 && enemyHP > 0) {

		action = battleMenu();

		system("cls");

		switch (action){
		case 1: 
			cout << "\n\nYou've used a sword attack!\n";

			swordDamage = 5 + (rand() % (15 - 5 + 1));

			cout << "You did " << swordDamage << " damage.\n\n";
			enemyHP = enemyHP - swordDamage;

			break;
		case 2: cout << "\n\nYou've defended against the " << enemyName << "'s attack!\n\n";
			isDefending = true;
			break;
		case 3: cout << "\n\nYou've cried like a little bitch! You look like a lady in danger now!\n\n";
			break;
		case 4: cout << "\n\nYou are trying to run...";
			//create run algorithm
			break;
		}

		system("pause");
		system("cls");

		cout << "The " << enemyName << " attacked!\n\n";

		if (isDefending) {
			cout << "... but " << warriorName << " defended!\n\n";
			isDefending = false;

			system("pause");
			system("cls");
		}
		else {
			enemyDamage = 5 + (rand() % (15 - 5 + 1));

			cout << "\n\nThe " << enemyName << " did " << enemyDamage << " damage.\n\n";
			warriorHP = warriorHP - enemyDamage;

			system("pause");
			system("cls");
		}
	}
}

int main() {

	cout << "Hello, my dear warrior. Welcome to the mighty kingdom of " << KINGDOM << "\n";
	cout << "Please, state thy name\n";
	setWarriorName();
	
	system("cls");

	cout << "Ah, " << warriorName << "...\nThat name indeed seems to hold a great power.\n\n";
	cout << "So, shall we begin?\n\nYou were walking down on your way home, wich is located in the easternmost part of the Alicaros Forest, when suddenly you hear someone screaming.\n\n";
	cout << "What are you gonna do?\n";
	cout << "1 - Follow the sound and see what is happening.\n";
	cout << "2 - Ignore that fucking screaming asshole and continue on your way home.\n";
	cin >> choice;

	validateChoice();

	system("cls");

	if (choice == 1){
		awesomePoints++;
		cout << "Ooh playing the nice guy, are not you?\n\n";
		forestLadyEncounter();

		if (!girlIsRaped) {
			cout << "As she was exiting the clearing, you saw a sharp and pointy thorn growing abruptly in the middle of her back.\n\nA giant spider trespassed her body like butter.";
		}
		else {
			cout << "\n\nAs you were exiting the clearing, a giant spider was coming down from above the trees.\n\n";
		}

		system("pause");
		system("cls");

		strcpy_s(enemyName, "Giant Spider");

		system("cls");

		battle();

		if (warriorHP == 0) {
			isWarriorDead = true;
		}
		else {
			cout << "You've fought bravely with the " << enemyName << " and killed it bravefuly. Thou are much strong indeed, warrior.\n\n";
			system("pause");
			system("cls");
		}

	}
	else {
		assholePoints++;
		cout << "Really? What an asshole you are.\n\nWell, you just ignored the screaming person out there.\n\n";
	}

	if (isWarriorDead){
		gameOver();
	}

	cout << "\n";
	system("pause");

	return 0;
}
