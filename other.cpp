#include <iostream>
using namespace std;

void check(int m){
  while (m > 8 || m < 0){
    cout << "Number is not valid. Enter a new number.\n";
    cin >> m;  //checks if number is valid
  }
}

//void check1(int num1[],string map3[][9]){ //checks so you don't have the same numbers
  //while (map3[num1[0]][num1[1]] == "-");
  //cout << "Point is already occupied. Pick another point\n";
  //cout << "How far down do you want your ship to be?\n";
  //cin >> num1[0];
  //check(num1[0]);
  //cout << "How far right do you want your ship to be?\n"; //just asks user where he will //place ship
  //cin >> num1[1];
  //check(num1[1]);
//} doesn't work


void ask(int num[], string map2[][9]){
  cout << "How far down do you want your ship to be?\n";
  cin >> num[0];
  check(num[0]);
  cout << "How far right do you want your ship to be?\n"; //just asks user where he will place ship
  cin >> num[1];
  check(num[1]);
  //check1(num, map2);
  map2[num[0]][num[1]] = "-";

  cout << "\n\n\n";
}

void eask(int num[], string emap2[][9], string map3[][9]){ //random points of enemy
  num[0] = rand() % 9;
  num[1] = rand() % 9;
  while(map3[num[0]][num[1]] == "-"){ //makes sure that emap and map won't overlap at any point
    num[0] = rand() % 9;
    num[1] = rand() % 9;
  }
  while(emap2[num[0]][num[1]] == "-"){ 
    num[0] = rand() % 9;
    num[1] = rand() % 9;  
  }
  emap2[num[0]][num[1]] = "-";

}

void cs(string emap2[][9]){
cout << "UAV incoming: Do you want the bottom third(1), middle third(2) or top third(3) of the grid for the enemy's ships? Press a number.";
int cheat1;
  cin >> cheat1;
  if (cheat1 == 3){
    cout << "This is the top third\n";
    for(int i = 0; i<3; i++){
      for(int p = 0; p<9; p++){
        cout << emap2[i][p] << " ";
      }
      cout << endl;
    }
  }
  if (cheat1 == 2){
    cout << "This is the middle third\n";
    for(int i = 3; i<6; i++){
      for(int p = 0; p<9; p++){
        cout << emap2[i][p] << " ";
      }
      cout << endl;
    }
  }
  if (cheat1 == 1){
    cout << "This is the bottom third\n";
    for(int i = 6; i<9; i++){
      for(int p = 0; p<9; p++){
        cout << emap2[i][p] << " ";
      }
      cout << endl;
    }
  }        
}
