#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;

void clearScreen() {
    const int PATCH_LINES = 30;
	for (int i = 0; i < PATCH_LINES; i++) cout << endl;
}

const string FIGURE[] = {
        "   -------------    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |           |    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          /     \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        " -----   \n"
    };

void renderGame(const string& guessedWord, const string& badGuesses) // hàm vẽ giá treo cổ, và số lần đoán sai // vẽ hoạt ảnh
{
    system("cls");
	//clearScreen();
	int badGuessCount = badGuesses.length();
	cout << FIGURE[badGuessCount] << endl;
	cout << "Secret word: " << guessedWord << endl;
	if (badGuessCount > 0) {
		cout << "You've made " << badGuessCount << " wrong ";
		cout << (badGuessCount == 1 ? "guess" : "guesses");
		cout << ": "<< badGuesses << endl;
	}
}

const string& getNextDancingMan() {
    const static string figure[] = {
    "     O     \n"
    "    /|\\   \n"
    "    | |    \n",
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n",
    "   __O__   \n"
    "     |     \n"
    "    / \\   \n",
    "    \\O/   \n"
    "     |     \n"
    "    / \\   \n",
    "   __O__   \n"
    "     |     \n"
    "    / \\   \n",
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "    O      \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "      O    \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,


    };
    const static int NUMBER_OF_FIGURES = sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
    return figure[(currentFigure++) % NUMBER_OF_FIGURES];
}

const string& getNextHangMan() {
    const static string figure[] = {
    "   ------------+    \n"
    "   |    /           \n"
    "   |    O      \n"
    "   |   /|\\    \n"
    "   |   / \\    \n"
    "   |        \n"
    " -----      \n" ,
    "   ------------+     \n"
    "   |     |           \n"
    "   |     O           \n"
    "   |    /|\\         \n"
    "   |    / \\         \n"
    "   |        \n"
    " -----      \n",
    "   ------------+     \n"
    "   |      \         \n"
    "   |      O          \n"
    "   |     /|\\        \n"
    "   |     / \\        \n"
    "   |      \n"
    " -----    \n",
    "   ------------+     \n"
    "   |     |           \n"
    "   |     O           \n"
    "   |    /|\\         \n"
    "   |    / \\         \n"
    "   |        \n"
    " -----      \n"
    };
    const static int NUMBER_OF_FIGURES = sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
    return figure[(currentFigure++) % NUMBER_OF_FIGURES];
}

//void displayFinalResult(bool won, const string& word) { // hàm in ra kết quả
//    while (true) {
//        system("cls");
//        //clearScreen();
//        if (won)
//            cout << "Congratulations! You win!" << endl;
//        else
//            cout << "You lost. The correct word is: "<< word
//            << endl;
//        cout << (won ? getNextDancingMan() : getNextHangMan());
//        this_thread::sleep_for(chrono::milliseconds(300));
//    }
//}

const string GAMEOVER[] ={
" -------------        \n"
" |           /        \n"
" |          O         \n"
" |        /|\\        \n"
" |        / \\        \n"
" |     \n"
" ----- \n",
" -------------        \n"
" |           |        \n"
" |           O        \n"
" |          /|\\      \n"
" |          / \\      \n"
" |     \n"
" ----- \n",
" -------------        \n"
" |            \\       \n"
" |             O      \n"
" |             /|\\   \n"
" |             / \\   \n"
" |     \n"
" ----- \n",
" -------------        \n"
" |           |        \n"
" |           O        \n"
" |          /|\\      \n"
" |          / \\      \n"
" |     \n"
" ----- \n",
" -------------         \n"
" |           /         \n"
" |          O          \n"
" |         /|\\        \n"
" |         / \\        \n"
" |     \n"
" ----- \n",
" -------------        \n"
" |           |        \n"
" |           O        \n"
" |          /|\\      \n"
" |          / \\      \n"
" |     \n"
" ----- \n",
" -------------        \n"
" |            \\       \n"
" |             O      \n"
" |            /|\\   \n"
" |            / \\   \n"
" |                    \n"
" ----- \n",
" -------------        \n"
" |           |        \n"
" |           O        \n"
" |          /|\\      \n"
" |          / \\      \n"
" |     \n"
" ----- \n",
" -------------        \n"
" |           /        \n"
" |          O         \n"
" |         /|\\        \n"
" |         / \\        \n"
" |     \n"
" ----- \n",
" -------------        \n"
" |           |        \n"
" |           O        \n"
" |          /|\\      \n"
" |          / \\      \n"
" |     \n"
" ----- \n",
" -------------        \n"
" |            \\       \n"
" |             O      \n"
" |            /|\\   \n"
" |            / \\   \n"
" |     \n"
" ----- \n",
" -------------        \n"
" |           |        \n"
" |           O        \n"
" |          /|\\      \n"
" |          / \\      \n"
" |     \n"
" ----- \n",
};
static string figure[] = {
" O \n"
" /|\\ \n"
" | | \n",
" O \n"
" /|\\ \n"
" / \\ \n",
" \O //\n"
"  | \n"
" / \\ \n",
" \\O/ \n"
"  | \n"
" / \\ \n",
" O \n"
" /|\ \n"
" / \\ \n",
"   O \n"
" /|\\ \n"
" / \\ \n" ,
" O \n"
" /|\\ \n"
" / \\ \n" ,
"   O \n"
" /|\\ \n"
" / \\ \n" ,
" O \n"
" /|\\ \n"
" / \\ \n" ,
"   O \n"
" /|\\ \n"
" / \\ \n" ,
};

void displayFinalResult(bool won, const string& word,int sum){
if(won){
        int i=0;
    while(i<10){
            system("cls");
           // for (int i = 0; i < 30; i++) cout << endl;
            cout << "Congratulations! You win! "<<"the word is "<<word<<endl;
             cout << "Your Point : "<<sum<<"/7"<<endl;
               cout<<figure[i];
               i++;
            this_thread::sleep_for(chrono::milliseconds(500));
		}
}

	else{
		int i=0;
		while(i<12){
                system("cls");
          // for (int i = 0; i < 30; i++) cout << endl;
        cout << "You lost. The correct word is: " << word<<endl;
        cout << "Your Point : "<<sum<<"/7"<<endl;
               cout<<GAMEOVER[i];

               i++;
            this_thread::sleep_for(chrono::milliseconds(500));
		}
	}
}
