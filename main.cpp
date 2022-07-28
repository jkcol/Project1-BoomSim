#include "other.cpp"
#include <iostream>
using namespace std;
int main() {
	int carrier[2], battleship[2], cruiser[2], submarine[2], destroyer[2],
		ammuntion[2], shooter[2], rocket[2], bomber[2], plane[2];
	string name;

	int ecarrier[2], ebattleship[2], ecruiser[2], esubmarine[2], edestroyer[2],
		eammuntion[2], eshooter[2], erocket[2], ebomber[2], eplane[2];
	string ename;

	int anum, anum2, eanum, eanum2,
		a1 = 10, a2 = 10, co = 0,
		cheat; // a1 and a2 are counters for amount of ship. co is a counter for
			   // the amount of times you play.

	string map[9][9];
	for (int i = 0; i < 9; i++) {
		for (int p = 0; p < 9; p++) {
			map[i][p] = "0";
		}
	}

	string emap[9][9];
	for (int i = 0; i < 9; i++) {
		for (int p = 0; p < 9; p++) {
			emap[i][p] = "0";
		}
	}

	string cmap[9][9];
	for (int i = 0; i < 9; i++) {
		for (int p = 0; p < 9; p++) {
			cmap[i][p] = "0";
		}
	}

	cout << "What is your name?\n";
	cin >> name;

	cout << "Hello " << name
		 << ", this is the BOOM SIM. You will place your ships and try to "
			"guess location of enemy ships and destroy them. Everyone has 10 "
			"ships. First one to destroy all enemy ships wins. \n";

	cout << "The ships are Carrier, Battleship, Cruiser, Submarine, and "
			"Destroyer, ammuntion, shooter, rocket, bomber, plane. Every ship "
			"occupies 1 space\n";

	for (int i = 0; i < 9; i++) {
		for (int p = 0; p < 9; p++) {
			cout << map[i][p] << "  ";
		}
		cout << "\n";
	}
	cout
		<< "Make sure that none of your pieces overlap or else you will be at "
		   "a disadvantage. Always enter a number between 0 and 8 inclusive.\n";

	// asking part

	cout << "Where do you want to place your Carrier?\n";
	ask(carrier, map);
	// here is where i will place the asak function which will ask which ship
	// you are placing so i can use that data for the next function here is
	// where I will place position function

	cout << "Where do you want to place your Battleship?\n";
	ask(battleship, map);

	cout << "Where do you want to place your Cruiser?\n";
	ask(cruiser, map);

	cout << "Where do you want to place your Submarine?\n";
	ask(submarine, map);

	cout << "Where do you want to place your Destroyer?\n";
	ask(destroyer, map);

	cout << "Where do you want to place your Ammunition?\n";
	ask(ammuntion, map);

	cout << "Where do you want to place your Shooter?\n";
	ask(shooter, map);

	cout << "Where do you want to place your Rocket?\n";
	ask(rocket, map);

	cout << "Where do you want to place your Bomber?\n";
	ask(bomber, map);

	cout << "Where do you want to place your Plane?\n";
	ask(plane, map);

	cout << "This is your map.\n";

	for (int i = 0; i < 9; i++) {
		for (int p = 0; p < 9; p++) {
			cout << map[i][p] << "  ";
		}
		cout << "\n";
	}

	eask(ecarrier, emap, map);
	eask(ebattleship, emap, map);
	eask(ecruiser, emap, map);
	eask(esubmarine, emap, map);
	eask(
		edestroyer,
		emap,
		map); // have to put "map" parameter in order to make sure that while
			  // loop below will work since map and emap cannot be the same. If
			  // they are the same the while loop will have ("true or true") and
			  // that will be false even though we want it to be true
	eask(eammuntion, emap, map);
	eask(eshooter, emap, map);
	eask(erocket, emap, map);
	eask(ebomber, emap, map);
	eask(plane, emap, map);

	while (a1 > 1 || a2 > 1) { // uses counter to end game
		cout << "Please select a point to attack.\n";
		cout << "How far down do you want you want to attack?\n";
		cin >> anum;
		check(anum);
		cout << "How far right do you want you want to attack?\n";
		cin >> anum2;
		check(anum2);
		if (emap[anum][anum2] == "-") { // checks if if you guesses are correct
			emap[anum][anum2] = "0";
			cout << "You hit a ship! Now it's the enemy's turn.\n";
			a2 -= 1; // counter for enemy ships
			cout << "You have " << a2 << " enemy ships left.\n";

		} else {
			cout << "You missed. Now it's the enemy's turn.\n";
		}
		eanum = rand() % 9;
		eanum2 = rand() % 9;
		while (emap[eanum][eanum2] ==
			   "-") { // makes sure enemy doesn't pick its own points
			eanum = rand() % 9;
			eanum2 = rand() % 9;
		}
		if (map[eanum][eanum2] == "-") {
			map[eanum][eanum2] = "0";
			cout << "You lost a ship!\n";
			a1 -= 1; // counter for personal ships
			cout << "You have " << a1 << " ships left.\n";
		} else {
			cout << "You still have " << a1 << " ships left.\n";
		}
		co += 1;
		if (co > 5 && a2 > 8) {
			cs(emap); // this is a cheat sheet because the game is very long
		}
		if (a1 == 0) {
			break;
		}
		if (a2 == 0) {
			break;
		}
	}

	if (a1 == 0) {
		cout << "You lost. Too bad, you lost the war.\n";
	} // ending
	if (a2 == 0) {
		cout << "You won! Now celebrate with all your friends!\n";
	}
}

// cout << "UAV incoming: Do you want the bottom third(1), middle third(2) or
// top third(3) of the grid for the enemy's ships? Press a number."; cin >>
// cheat; if (cheat == 3){
//   cout << "This is the top third";
//   for(int i = 0; i<3; i++){
//     for(int p = 0; p<9; p++){
//       cout << emap[i][p] << " ";
//     }
//     cout << endl;
//   }
// }
// if (cheat == 2){
//   cout << "This is the middle third";
//   for(int i = 3; i<6; i++){
//     for(int p = 0; p<9; p++){
//       cout << emap[i][p] << " ";
//     }
//     cout << endl;
//   }
// }
// if (cheat == 1){
//   cout << "This is the bottom third";
//   for(int i = 6; i<9; i++){
//     for(int p = 0; p<9; p++){
//       cout << emap[i][p] << " ";
//     }
//     cout << endl;
//   }
// }
