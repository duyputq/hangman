#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>
#include <algorithm>
#include "draw.h"

using namespace std;

const int MAX_BAD_GUESSES = 7;


string chooseWord(); // hàm chọn từ  //pải lấy từ file
char readAGuess();    // hàm nhập vào input
bool contains(const string& word, char guess); // hàm kiểm tra đúng sai từ nhập vào
void updateGuessedWord(string& guessedWord, const string& word, char guess); // update hiển thị xuất hiện từ cần đoán
char getButton();
int main()
{
	srand(time(0));
	char button;
	while (true){
	string word = chooseWord(); // chọn 1 từ từ file
	if (word.length() < 1) {
		cout << "Error reading vocabulary file " ;
		return -1;
	}
	cout << word<<endl;
	string guessedWord = string(word.length(), '-');
	string badGuesses = "";

	do {
		renderGame(guessedWord, badGuesses); // vẽ giá treo
		char guess = readAGuess();   // nhập vào chữ đoán tiếp theo (input)
		if (contains(word, guess))  // kiểm tra đúng, sai, nếu đúng thì thay đổi còn ko thì kệ
			updateGuessedWord(guessedWord, word, guess);
		else {
			badGuesses += guess;        // từ đoán sai +1
		}
	} while (badGuesses.length() < MAX_BAD_GUESSES && word != guessedWord);
    displayFinalResult(badGuesses.length() < MAX_BAD_GUESSES, word);

    cout << "Do you want to play this game again? (y/n)"<<endl;
        button = getButton();
        if (button == 'n'){
            break;
        }
        system("cls");
//    system("pause");
	}
	return 0;
}

string getLowerCaseString(const string& s)
{
    string res = s;
    transform(s.begin(), s.end(), res.begin(), ::tolower);
    return res;
}

int Picktopick(){
    int n;
    cout<<"Press 1 : Animal"<<endl;
    cout<<"Press 2 : Fruit"<<endl;
    cout<<"Press 3 : Job"<<endl;
    cout<<"Press 4 : All Subjects"<<endl;
    cout<<"Your choice is: ";
    cin>>n;
    return n;
}

string chooseWord()
{
	vector<string> wordList;
	int k = Picktopick  ()  ;
    string path ;
    if(k==1)path="animal.txt";
    if(k==2)path="job.txt";
    if(k==3)path="fruit.txt";
    if(k==4)path="1.txt";
	ifstream file(path);
  	if (file.is_open()) {
	    string word;
		while (file >> word) {
            wordList.push_back(word);
        }
    	file.close();
  	}
  	if (wordList.size() > 0) {
  		int randomIndex = rand() % wordList.size();
    	return getLowerCaseString(wordList[randomIndex]);
	} else return "";
}




char readAGuess()
{
	char input;
	cout << "Your guess: ";
	cin >> input;
	return tolower(input);
}

bool contains(const string& word, char c)
{
	return (word.find_first_of(c) != string::npos);
}

void updateGuessedWord(string& guessedWord, const string& word, char guess)
{
	for (int i = word.length() - 1; i >= 0; i--) {
        if (word[i] == guess) {
            guessedWord[i] = guess;
        }
    }
}

char getButton()
{
    char button;
    while (true){
        cout << "Your choice is: ";
        cin >> button;
        if (button == 'y' || button == 'n') break;
        else{
            cout << "Wrong button!" << endl
                 << "Press y to continue" << endl
                 << "Press n to quit the game" << endl;
        }
    }
    return button;
}
