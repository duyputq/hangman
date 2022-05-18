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
    int sum = 7;
	while (true){

	string word = chooseWord(); // chọn 1 từ từ file
	if (word.length() < 1) {
		cout << "Error reading vocabulary file " ;
		return -1;
	}
	cout << word<<endl;
	string guessedWord = string(word.length(), '-');
	string badGuesses = "";
    system("cls");
	do {
		renderGame(guessedWord, badGuesses); // vẽ giá treo
		char guess = readAGuess();   // nhập vào chữ đoán tiếp theo (input)
		if (contains(word, guess))  // kiểm tra đúng, sai, nếu đúng thì thay đổi còn ko thì kệ
			updateGuessedWord(guessedWord, word, guess);
		else {
			badGuesses += guess;        // từ đoán sai +1
			sum = sum -1;
		}
	} while (badGuesses.length() < MAX_BAD_GUESSES && word != guessedWord);
    displayFinalResult(badGuesses.length() < MAX_BAD_GUESSES, word, sum);

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
    cout<<"Choose subject!"<<endl;
    cout<<"Press 1 : Animal"<<endl;
    cout<<"Press 2 : Fruit"<<endl;
    cout<<"Press 3 : Job"<<endl;
    cout<<"Press 4 : All Subjects"<<endl;
    cout<<"Your choice is: ";
    cin>>n;
    cout << endl;
    return n;
}

int ChooseLevel(){
   int n;
   cout<<"Choose level!"<<endl;
   cout<<"Press 1 : Easy"<<endl;
    cout<<"Press 2 : Normal"<<endl;
    cout<<"Press 3 : Hard"<<endl;
    cout <<"Your choice is: ";
    cin>>n;
   return n;
}


string chooseWord()
{
	vector <string> WORD_LIST;
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
            WORD_LIST.push_back(word);
        }
    	file.close();
  	}
    int z = ChooseLevel () ;
     if(z==1){
    srand(time(NULL));
    int RandomIndex= rand() % WORD_LIST.size();
    while(WORD_LIST[RandomIndex].length()>3){
            srand(time(NULL));
     RandomIndex= rand() % WORD_LIST.size();
    }
    getLowerCaseString(WORD_LIST[RandomIndex]);

        return WORD_LIST[RandomIndex];
     }
     if(z==2){
    srand(time(NULL));
    int RandomIndex= rand() % WORD_LIST.size();
    while(WORD_LIST[RandomIndex].length()>4||WORD_LIST[RandomIndex].length()<=3){
            srand(time(NULL));
     RandomIndex= rand() % WORD_LIST.size();
    }
    getLowerCaseString(WORD_LIST[RandomIndex]);

        return WORD_LIST[RandomIndex];
     }
     if(z==3){
    srand(time(NULL));
    int RandomIndex= rand() % WORD_LIST.size();
    while(WORD_LIST[RandomIndex].length()<5){
            srand(time(NULL));
     RandomIndex= rand() % WORD_LIST.size();
    }
    getLowerCaseString(WORD_LIST[RandomIndex]);

        return WORD_LIST[RandomIndex];
     }

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
