#include <iostream>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <random>
using namespace std;
int const MAX = 100;
char character_name[MAX];
vector <string> weapons = { "The forgotten blade", "Warmogs armor", "Knights helmet", "Boots of swiftness" };
vector <string> inventory = {};

void map_display(int current_room);
void choose_room(int* current_room);
void display_inventory(vector <string> items);
void boss_display(int damage);
void Game1();
void Game2();
void Game3();
void Game4();
void Game5();
void Game6();
void Boss_room(vector <string> items, string character_name);

void clearscreen() {
    system("cls");
}

void display_inventory(vector <string> weapons) {
    if (weapons.size() == 0){
        cout<<"Your bag is empty!"<<endl;
    }
    else{
        cout<<"Your bag: \n";
        for (int i = 0; i < weapons.size(); i++) {
            cout << weapons[i] << "\n";
        }
    }
}

void menu_display() {
    cout << "=====\n"
        << "1. Map\n"
        << "2. Choose room\n"
        << "3. Inventory\n"
        << "4. Exit game\n"
        << "=====\n";
}

void map_display(int current_room) {
    char board[MAX][MAX];
    string row24 = "|-------------------------------------------------------|\n";
    string row23 = "|                  |- ENDING POINT  -|                  |\n";
    string row22 = "|                  |                 |                  |\n";
    string row21 = "|                  |                 |                  |\n";
    string row20 = "|                  |         7       |                  |\n";
    string row19 = "|                  |                 |                  |\n";
    string row18 = "|                  |                 |                  |\n";
    string row17 = "|                  |-----|     |-----|                  |\n";
    string row16 = "|                                         |-------------|\n";
    string row15 = "|                     |-------------|     |             |\n";
    string row14 = "|---------|           |      6      |     |       5     |\n";
    string row13 = "|         |           |------------|    |-|             |\n";
    string row12 = "|     4   |--|                         |----------------|\n";
    string row11 = "|------------|                                          |\n";
    string row10 = "|                   |--------------|                    |\n";
    string row09 = "|                   |    |-3-|     |                    |\n";
    string row08 = "|                   |--------------|                    |\n";
    string row07 = "|------------|                            |-------------|\n";
    string row06 = "|            |                            |             |\n";
    string row05 = "|      1     |                            |     2       |\n";
    string row04 = "|------------|                            |-------------|\n";
    string row03 = "|                 |-------|   |------|                  |\n";
    string row02 = "|                 |         0        |                  |\n";
    string row01 = "|                 |- STARTING POINT -|                  |\n";
    string row00 = "|-------------------------------------------------------|\n";
    for (int j = 0; j < 57; j++) {
        board[0][j] = row24[j];
        board[1][j] = row23[j];
        board[2][j] = row22[j];
        board[3][j] = row21[j];
        board[4][j] = row20[j];
        board[5][j] = row19[j];
        board[6][j] = row18[j];
        board[7][j] = row17[j];
        board[8][j] = row16[j];
        board[9][j] = row15[j];
        board[10][j] = row14[j];
        board[11][j] = row13[j];
        board[12][j] = row12[j];
        board[13][j] = row11[j];
        board[14][j] = row10[j];
        board[15][j] = row09[j];
        board[16][j] = row08[j];
        board[17][j] = row07[j];
        board[18][j] = row06[j];
        board[19][j] = row05[j];
        board[20][j] = row04[j];
        board[21][j] = row03[j];
        board[22][j] = row02[j];
        board[23][j] = row01[j];
        board[24][j] = row00[j];
    }
    // Clear the previous player position
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 57; j++) {
            if (board[i][j] == 'X') {
                board[i][j] = ' ';
            }
        }
    }
    // Display the player's position
    if (current_room == 1) {
        board[19][7] = 'X';
    }
    else if (current_room == 2) {
        board[19][48] = 'X';
    }
    else if (current_room == 3) {
        board[15][27] = 'X';
    }
    else if (current_room == 4) {
        board[12][6] = 'X';
    }
    else if (current_room == 5) {
        board[10][50] = 'X';
    }
    else if (current_room == 6) {
        board[10][29] = 'X';
    }
    else if (current_room == 7) {
        board[4][28] = 'X';
    }

    // Generate map
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 57; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

void boss_display(int damage) {
    char board[MAX][MAX];
    string row13 = "|-------------------------------------------------------|\n";
	string row12 = "|               /II                        /ii          |\n";
	string row11 = "|               IIII                      /  /          |\n";
	string row10 = "|                IIII_____          _____/  /           |\n";
	string row09 = "|                 II____ II   /II  //  ____/            |\n";
	string row08 = "|                  II II  II  II/ //  // //             |\n";
	string row07 = "|                   ||II0III     //  /0////             |\n";
	string row06 = "|                   ||  II| |    |  |/x^x||             |\n";
	string row05 = "|                   ||    | |    |  |  x ||             |\n";
	string row04 = "|                    II   | II__//  |   //              |\n";
	string row03 = "|                     II  II  OO   //  //               |\n";
	string row02 = "|                      II<<|||||||||>>//                |\n";
	string row01 = "|                       II<<|||||||>>//                 |\n";
	string row00 = "|-------------------------------------------------------|\n";
    for (int j = 0; j < 57; j++) {
        board[0][j] = row13[j];
        board[1][j] = row12[j];
        board[2][j] = row11[j];
        board[3][j] = row10[j];
        board[4][j] = row09[j];
        board[5][j] = row08[j];
        board[6][j] = row07[j];
        board[7][j] = row06[j];
        board[8][j] = row05[j];
        board[9][j] = row04[j];
        board[10][j] = row03[j];
        board[11][j] = row02[j];
        board[12][j] = row01[j];
        board[13][j] = row00[j];
    }
    if (damage == 0){

    }
    else{
        string digitString = to_string(damage);  // Convert damage to a string
        // Now assign the two characters of the string to the board 
        board[6][5] = '-';
        board[6][6] = digitString[0];
        board[6][7] = digitString[1];
    }
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 57; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

void choose_room(int* current_room) {
    int choice;
    if (*current_room == 0) {
        cout
            << "Choose room by entering the number corresponding to the room you want: " << endl
            << "=====\n"
            << "1. Room 1\n"
            << "2. Room 2\n"
            << "=====\n"
            << "Your option: ";
        cin >> choice;
        if (choice == 1 || choice == 2){
            *current_room =  choice;
        }
        else{
            cout<<"Please enter the correct number."<<endl;
        }
    }
    else if (*current_room == 1 || *current_room == 2) {
        cout
            << "=====\n"
            << "3. Room 3\n"
            << "=====\n"
            << "From here you can only go to room 3, press enter to continue...";
        while (cin.get() != ' ');
        cout << "Continuing...\n";
        Sleep(2000);
        choice = 3;
        *current_room = choice;
    }
    else if (*current_room == 3) {
        cout
            << "Choose room by entering the number corresponding to the room you want: " << endl
            << "=====\n"
            << "4. Room 4\n"
            << "5. Room 5\n"
            << "6. Room 6\n"
            << "=====\n"
            << "Your option: ";
        cin >> choice;
        *current_room = choice;
        if (choice == 4 || choice == 5 || choice == 6){
            *current_room =  choice;
        }
        else{
            cout<<"Please enter the correct number."<<endl;
        }
    }
    else if (*current_room == 4) {
        cout
            << "=====\n"
            << "6. Room 6\n"
            << "=====\n"
            << "From here you can only go to room 6, press enter to continue...";
        while (cin.get() != ' ');
        cout << "Continuing...\n";
        Sleep(2000);
        *current_room = 6;
    }
    else if (*current_room == 5) {
        cout
            << "=====\n"
            << "6. Room 6\n"
            << "=====\n"
            << "From here you can only go to the room 6, press enter to continue...";
        while (cin.get() != ' ');
        cout << "Continuing...\n";
        Sleep(2000);
        *current_room = 6;
    }
    else if (*current_room == 6) {
        cout
            << "=====\n"
            << "7. Hall of the Dragon\n"
            << "=====\n"
            << "From here you can only go to the boss room, press enter to continue...";
        while (cin.get() != ' ');
        cout << "Continuing...\n";
        Sleep(2000);
        *current_room = 7;
    }
    switch (*current_room) {
    case 1: {
        Game1();
        break;
    }
    case 2: {
        Game2();
        break;
    }
    case 3: {
        Game3();
        break;
    }
    case 4: {
        Game4();
        break;
    }
    case 5: {
        Game5();
        break;
    }
    case 6: {
        Game6();
        break;
    }
    case 7: {
        Boss_room(inventory, character_name);
        break;
    }
    }
}

void Game1() {
    char input[MAX];
    char ans[] = "21467";
    printf("You got yourself into a small dungeon. \n");
    printf("As you exploring, you found a locked room with a message on the door(maybe its a riddle?) \n");
    printf("12$GL\n");
    Sleep(1000);
    printf("When the sun and the moon combine, two becomes one, and one becomes twice. \nThe sign of Rebmun once arises. \nXis and Neves assemble, you will get what you want to find....\n");
    printf("Answer (numbers only): ");
    scanf("%s", input);
    int temp = strcmp(input, ans);
    //answer checking
    if (temp == 0) {
        printf("Congrats, that's the correct answer!\n");
        Sleep(2000);
        printf("At the corner of the room, you notice that something is shining. \n");
        Sleep(2000);
        printf("You found an old blade! \n");
        Sleep(2000);
        printf("'The forgotten blade' has been transferred to your inventory \n");
        Sleep(2000);
        inventory.push_back("The forgotten blade");
    }
    else {
        cout << "Wrong!" << endl;
        Sleep(1000);
        cout << "You have failed the challenge!" << endl;
        Sleep(2000);
        while (true) {
            int choice;
            cout << "Retry?" << endl;
            cout << "1. Yes           2. No" << endl;
            cout << "Your option: ";
            cin >> choice;
            if (choice == 1) {
                Game1();
                break;
                cout << endl;
            }
            else if (choice == 2) {
                cout << "You have failed the challenge" << endl;
                Sleep(2000);
                break;
            }
            else {
                cout << "You should enter the number corresponding to the the given options" << endl;
                Sleep(2000);
                continue;
            }
        }
    }
}

void Game2() {
    int choice;
    cout<<"You encounter a matrice carved on a crate with missing numbers."<<endl;
    Sleep(2000);
    cout << "In this game you will have to fill the correct number in the missing spaces" << endl;
    Sleep(2000);
    cout << "Hint: The matrice has very special rule and the name of it reffered to a famous Italian Mathematician" << endl;
    Sleep(2000);
    int board[MAX][MAX] = {
                          {1 ,  21  , 0    , 0  },
                          {1 ,  13  , 55   , 610},
                          {2 ,  0   , 89   , 0  },
                          {3 ,  5   , 144  , 233}
    };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                board[i][j] = ' ';
            }
            else {
                cout << board[i][j];
            }
            cout << "\t";
        }
        cout << endl;
    }
    cout << "Input a value for spot 2-1: ";
    cin >> board[2][1];
    cout << "Input a value for spot 0-2: ";
    cin >> board[0][2];
    cout << "Input a value for spot 2-3: ";
    cin >> board[2][3];
    cout << "Input a value for spot 0-3: ";
    cin >> board[0][3];
    if (board[2][1] == 8 && board[0][2] == 34 && board[2][3] == 377 && board[0][3] && 987) {
        cout << "Congratulations! You have won the challenge " << endl;
        Sleep(2000);
        cout<<"The matrice activated and open the chest."<<endl;
        Sleep(2000);
        cout<<"You found a chestplate inside of it!"<<endl;
        Sleep(2000);
        inventory.push_back("Warmogs armor");
    }
    else {
        cout << "You have failed the challenge!" << endl;
        Sleep(2000);
        while (true) {
            cout << "Retry?" << endl;
            cout << "1. Yes           2. No" << endl;
            Sleep(2000);
            cout << "Your option: ";
            cin >> choice;
            if (choice == 1) {
                Game2();
                break;
            }
            else if (choice == 2) {
                cout << "You have failed the challenge" << endl;
                Sleep(2000);
                break;
            }
            else {
                cout << "You should enter the number corresponding to the the given options" << endl;
                Sleep(2000);
                continue;
            }
        }
    }
}

void Game3() {
    char ans[MAX];
    printf("Unknown signs are carved on the wall, try to figure them out!\n");
    Sleep(2000);
    printf("-.-- --- ..- / .- .-. . / .-- .-. --- -. --.\n");
    Sleep(2000);
    printf("Answer (lowercase only): ");
    cin.ignore();
    cin.getline(ans, 99);
    int temp = strcmp(ans, "you are wrong");
    if (temp == 0) {
        printf("Well done! \n");
        Sleep(1000);
        printf("The signs starting to shine, you feel that something is activating \n");
        Sleep(1000);
        printf("The wall in front of you suddenly collapsed! \n");
        Sleep(1000);
        printf("But theres nothing in there (maybe its being taken?) \n");
        Sleep(1000);
    }
    else if (temp != 0) {
        int choice;
        cout<<"You have failed the challenge!\n";
        Sleep(1000);
        cout<<"Wanna retry?\n";
        cout << "Retry?" << endl;
        cout << "1. Yes           2. No" << endl;
        Sleep(2000);
        while (true) {
            cout << "Your option: ";
            cin >> choice;
            if (choice == 1) {
                Game3();
                break;
            }
            else if (choice == 2) {
                cout << "You have failed the challenge" << endl;
                Sleep(2000);
                break;
            }
            else {
                cout << "You should enter the number corresponding to the options" << endl;
                Sleep(2000);
                continue;
            }
        }
    }
}

void Game4() {
    char ans[MAX];
    int retry;
    printf("You notice a black and white matrice on the ground and a horse-like statue with a sign: \n");
    Sleep(1000);
    printf("In a sixty-four-squares land, white knights are ready to go, where should they go? \n");
    Sleep(1000);
    printf("Your answer is (A3): ");
    cin.ignore();
    cin.getline(ans, MAX);
    if (strcmp(ans, "A3") == 0) {
        printf("Congrats my fella, you have an exellent intelligence!\n");
    }
    else if (strcmp(ans, "C3") == 0) {
        printf("Another method but the same result! Congrats!\n");
    }
    else if (strcmp(ans, "F3") == 0) {
        printf("Well done my friend!\n");
    }
    else if (strcmp(ans, "H3") == 0) {
        printf("All roads lead to Rome! Well done!\n");
    }
    else{
        int choice;
        cout<<"You have failed the challenge!\n";
        Sleep(1000);
        cout<<"Wanna retry?\n";
        cout << "Retry?" << endl;
        cout << "1. Yes           2. No" << endl;
        Sleep(2000);
        while (true) {
            cout << "Your option: ";
            cin >> choice;
            if (choice == 1) {
                Game4();
                break;
            }
            else if (choice == 2) {
                cout << "You have failed the challenge" << endl;
                Sleep(2000);
                break;
            }
            else {
                cout << "You should enter the number corresponding to the options" << endl;
                Sleep(2000);
                continue;
            }
        }
    }
    cout<<"The chess board collapses on its own and creates a huge hole. \n";
    Sleep(2000);
    cout<<"You found a cave inside of it! \n";
    Sleep(2000);
    cout<<"Inside the deepest part of the cave, you find a grave of a warior with a helmet on it! \n";
    Sleep(2000);
    cout<<"You found 'Knights helmet' \n";
    Sleep(2000);
    cout<<"'Knights helmet' has been transferred to your inventory \n";
    inventory.push_back("Knights helmet");
}

void Game5() {
    int result;
	char str[100];
	char pass[] = "winner or loser is the same";
    printf("You encounter a strange man, with a mysterious box\n");
    Sleep(2000);
	printf("Dear fellow player, can you solve this password ?\n");
    Sleep(2000);
	printf("9444666633777 666777 555666777733777 4447777 84433 77772633\n");
    Sleep(2000);
	printf("type your answer here: ");
	cin.ignore();
    cin.getline(str, MAX);
	result = strcmp(str, pass);
	if (result == 0) {
		printf("you are correct, congratulations! \n");
        Sleep(2000);
        printf("The boxs oppened, but theres nothing inside... \n");
        Sleep(2000);
        printf("The man then laugh and disappear in the shadow... \n");
        Sleep(2000);
	}
	else{
        int choice;
        cout<<"You have failed the challenge!\n";
        Sleep(1000);
        cout<<"Wanna retry?\n";
        cout << "Retry?" << endl;
        cout << "1. Yes           2. No" << endl;
        Sleep(2000);
        while (true) {
            cout << "Your option: ";
            cin >> choice;
            if (choice == 1) {
                Game5();
                break;
            }
            else if (choice == 2) {
                cout << "You have failed the challenge" << endl;
                Sleep(2000);
                break;
            }
            else {
                cout << "You should enter the number corresponding to the options" << endl;
                Sleep(2000);
                continue;
            }
        }
    }
}

void gotoxy(int x,int y)
{
//declare a COORD structure, represents a point in a 2-dimensional 
    COORD coord = {x,y};
/*This function call sets the cursor position in the console to the 
coordinates specified by the coord variable*/
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void Game6(){
    cout<<"Welcome to the great maze!"<<endl;
    Sleep(2000);
    cout<<"In order to get to the boss room, you have to get pass this maze."<<endl;
    Sleep(2000);
    cout<<"Press enter to continue..."<<endl;
    while (cin.get() != ' ');
    cout << "Continuing...\n";
    Sleep(2000);
    char board[MAX][MAX];
    string row13 = ">     --------------------------------------------------|\n";
    string row12 = "|                                                       |\n";
    string row11 = "|                                                       |\n";
    string row10 = "|         ------------------------------------|         |\n";
    string row09 = "|         |                                   |         |\n";
    string row08 = "|         |                                   |         |\n";
    string row07 = "|         |         ---------|        |       |         |\n";
    string row06 = "|         |                  |        |       |         |\n";
    string row05 = "|         |                  |        |       |         |\n";
    string row04 = "|         |         |--------|        |       |---------|\n";
    string row03 = "|                   |                 |                 >\n";
    string row02 = "|                   |                 |                 >\n";
    string row01 = "|                   |                 |                 |\n";
    string row00 = "|-------------------------------------------------------|\n";
    for (int j = 0; j < 57; j++) {
        board[0][j] = row13[j];
        board[1][j] = row12[j];
        board[2][j] = row11[j];
        board[3][j] = row10[j];
        board[4][j] = row09[j];
        board[5][j] = row08[j];
        board[6][j] = row07[j];
        board[7][j] = row06[j];
        board[8][j] = row05[j];
        board[9][j] = row04[j];
        board[10][j] = row03[j];
        board[11][j] = row02[j];
        board[12][j] = row01[j];
        board[13][j] = row00[j];
    }
	  
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 57; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
	
	int a,b,c;
	char obj;
	
	a=1;
	b=1;
	
    printf("Press enter to start the game : ");
    scanf("%c",&obj);

    system("cls");
    gotoxy(a,b);
    printf("%c",obj);
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 57; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }

    while(true){
    //kbhit stands for keyboard hit, this command is used to determine that
    //the user press a keyboard button. 
	    if(kbhit()){
	        c=getch();
    //77, 75, 72 and 80 are the numbers represent the arrow keys in ASCII format
    //In this program I will use arrow keys for character movement.
		    int new_a = a, new_b = b;
            if(c==77) new_a++;
            if(c==75) new_a--;
            if(c==72) new_b--;
            if(c==80) new_b++;

        if (board[new_b][new_a] != '-' && board[new_b][new_a] != '|') {  // Check for collision
            a = new_a;
            b = new_b;
        }
		
	    system("cls");
	    printf("%c",obj);
        for (int i = 0; i < 14; i++) {
            for (int j = 0; j < 57; j++) {
            cout << board[i][j];
        }
        cout << "\n";
        }
	    gotoxy(a,b);
	    if(a==56 && b==11){
		    system("cls");
		    printf("You won! \n");
            Sleep(2000);
            printf("At the exit of the maze, you found a golden chest! \n");
            Sleep(2000);
            printf("You got the 'Boots of swiftness' \n");
            Sleep(2000);
            printf("'Boots of swiftness' has been transferred to your inventory. \n");
            Sleep(2000);
            inventory.push_back("Boots of swiftness");
            break;
	    }
	    }	             
    }	                          
}
void Boss_room(vector <string> items, string name) {
    int player_health = 100;
    int player_max_health = player_health;
    int player_atk = 10;
    int boss_health = 300;
    int boss_atk = 20;
    int potion = 3;
    int damage = 0;
    cout << "Congrats on making it this far!" << endl
        << "In this final game, you will have to fight an Almighty Dragon!" << endl
        << "Based on the items you received from progression, you will be blessed with additional stats which will help you defeat the boss easier" << endl;
    Sleep(4000);
    cout << "This is your current stats: " << endl
        << "Character name: " << name << endl;
    Sleep(1000);
    cout << "Health: " << player_health << endl;
    Sleep(1000);
    cout << "Atk: " << player_atk << endl;
    Sleep(1000);
    cout << "Items that you have: ";
    for (int i = 0; i < items.size(); i++) {
        cout << items[i] << " ";
        if (items[i] == "The forgotten blade") {
            player_atk *= 2;
        }
        if (items[i] == "Warmogs armor") {
            player_health *= 2;
            player_max_health = player_health;
        }
        if (items[i] == "Knights helmet") {
            player_health += 100;
            player_max_health = player_health;
        }
    }
    Sleep(1000);
    cout << endl;
    cout
    << "This is your new stats: " << endl
    << "Character name: " << name << endl;
    Sleep(1000);
    cout << "Health: " << player_max_health << endl;
    Sleep(1000);
    cout << "Atk: " << player_atk << endl;
    Sleep(1000);
    cout << "Press space to continue...";
    while (cin.get() != ' ');
    Sleep(1000);
    cout << "Loading..." << endl;
    Sleep(2000);
    clearscreen();
    while (player_health > 0 && boss_health > 0) {
        int option;
        boss_display(damage);
        cout << endl;
        cout << "Player Health: " << player_health << endl;
        cout << "Boss Health: " << boss_health << endl
            << "=============" << endl
            << "1. Attack" << endl
            << "2. Heal" << "(You got " << potion << " left)" << endl;
        cout << "Your option: ";
        cin >> option;
        switch (option) {
        case 1: {
            clearscreen();
            int player_skill = rand() % 2 + 1;
            if (player_skill == 1) {
                cout << "You slashed the Dragon and dealt " << player_atk << " damage" << endl;
                boss_health -= player_atk;
                damage = player_atk;
            }
            else if (player_skill == 2) {
                cout << "You landed a critical strike and dealt " << player_atk * 1.5 << " damage" << endl;
                boss_health -= player_atk * 1.5;
                damage = player_atk * 1.5;
            }
            Sleep(1000);
            break;
        }
        case 2: {
            cout << "You have used a potion!" << endl;
            Sleep(1000);
            player_health += 50;
            if (player_health > player_max_health) {
                player_health = player_max_health;
                damage = 0;
            }
            potion--;
            cout << "Your health is now: " << player_health;
            Sleep(2000);
            clearscreen();
            break;
        }
        }
        int dodge_chance;
        int boss_skill = rand() % 2 + 1;
        for (int i = 0; i < items.size(); i++) {
            if (items[i] == "Boots of swiftness") {
                dodge_chance = rand() % 2 + 1;
            }
        }
            if (boss_skill == 1) {
                cout << "You got slashed by the Dragon that dealt " << boss_atk << " damage" << endl;
                Sleep(1000);
                if (dodge_chance == 1){
                    cout<<"But you dodged it thanks to the 'Boots of swiftness'!"<<endl;
                    Sleep(1500);
                }
                else{
                    player_health -= boss_atk;
                }
            }
            else if (boss_skill == 2) {
                cout << "The dragon used its Fire Breath that dealt " << boss_atk * 2 << " damage" << endl;
                Sleep(1000);
                if (dodge_chance == 1){
                    cout<<"But you dodged it thanks to the 'Boots of swiftness'!"<<endl;
                    Sleep(1500);
                }
                else{
                    player_health -= boss_atk * 2;
                }
        }
    if (player_health <= 0){
        cout<<"YOU DIED"<<endl;
        Sleep(1000);
        cout<<"Quittin...";
        Sleep(3000);
    }
    else if (boss_health <= 0){
        cout<<"Congratulations, you have won the game"<<endl;
        Sleep(1000);
        cout<<"Quittin...";
        Sleep(3000);
    }
    else if(player_health <= 0 && boss_health <= 0){
        cout<<"Both died"<<endl;
        cout<<"Its a DRAW!"<<endl;
        Sleep(1000);
        cout<<"Quittin...";
        Sleep(3000);
    }
}
}

int main() {
    int current_room = 0;
    cout
        << "\n*****************************************************************************************************************" << endl;
    cout << "\t\t\t ---Welcome to the Dungeon Quest---" << endl;
    Sleep(2000);
    cout << "What should we call you?" << endl
        << ">> ";
    cin.getline(character_name, 99);
    cout << "We shall call you '" << character_name << "' from now on" << endl;
    Sleep(2000);
    cout << "Welcome " << character_name << " to the Dragon Quest!" << endl;
    Sleep(2000);
    cout << "This game is quite simple.\n"
        "All you have to do is to find your way to different rooms, solve puzzles, riddles to get powerful items in order to defeat the final boss!" << endl;
    Sleep(2000);
    cout << "Are you ready to start?" << endl;
    Sleep(2000);
    cout << "Press space to continue...";
    while (cin.get() != ' ');
    cout << "Continuing...\n";
    Sleep(2000);
    cout << "Great! Lets get started" << endl;
    Sleep(5000);
    clearscreen();
    while (true) {
        int choice;
        if (current_room == 7){
            break;
        }
        menu_display();
        cout << "Your option: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            map_display(current_room);
            break;
        }
        case 2: {
            choose_room(&current_room);
            break;
        }
        case 3: {
            display_inventory(inventory);
            break;
        }
        case 4: {
            return 0;
        }
        default:{
            continue;
        }
        }
    }
}