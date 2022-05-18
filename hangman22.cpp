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

const char DATA_FILE[] = "D:\\Baitap\\Freshman2\\hangman\\1.txt";
string chooseWord(const char* fileName); // hàm chọn từ  //pải lấy từ file
char readAGuess();    // hàm nhập vào input
bool contains(const string& word, char guess); // hàm kiểm tra đúng sai từ nhập vào
void updateGuessedWord(string& guessedWord, const string& word, char guess); // update hiển thị xuất hiện từ cần đoán

int main()
{
	srand(time(0));
	string word = chooseWord(DATA_FILE); // chọn 1 từ từ file
	if (word.length() < 1) {
		cout << "Error reading vocabulary file " << DATA_FILE;
		return -1;
	}
	cout << word;
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
    system("pause");
	return 0;
}

string getLowerCaseString(const string& s)
{
    string res = s;
    transform(s.begin(), s.end(), res.begin(), ::tolower);
    return res;
}

string chooseWord(const char* fileName)
{
	vector<string> wordList;
	ifstream file(fileName);
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
