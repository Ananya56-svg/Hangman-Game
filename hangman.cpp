#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class HangmanGame {
    string word;
    string displayWord;
    vector<char> guessedLetters;
    int maxAttempts;
    int wrongAttempts;

public:
    HangmanGame() {
        maxAttempts = 6;
        wrongAttempts = 0;
        loadRandomWord();
        initializeDisplayWord();
    }

    void loadRandomWord() {
        vector<string> wordList;
        string w;
        ifstream file("words.txt");

        if (!file) {
            cout << "Error: Could not open words.txt file.\n";
            exit(1);
        }

        while (file >> w) {
            wordList.push_back(w);
        }
        file.close();

        if (wordList.empty()) {
            cout << "Error: Word list is empty.\n";
            exit(1);
        }

        srand(time(0));
        word = wordList[rand() % wordList.size()];
    }

    void initializeDisplayWord() {
        displayWord = string(word.length(), '_');
    }

    void displayStatus() {
        cout << "\nWord: ";
        for (char c : displayWord) {
            cout << c << " ";
        }
        cout << "\nWrong Attempts: " << wrongAttempts << "/" << maxAttempts << endl;
        drawHangman();
    }

    void drawHangman() {
        string hangman[7] = {
            "",
            "   O",
            "   O\n   |",
            "   O\n  /|",
            "   O\n  /|\\",
            "   O\n  /|\\\n  / ",
            "   O\n  /|\\\n  / \\"
        };
        cout << "\n" << hangman[wrongAttempts] << endl;
    }

    bool isAlreadyGuessed(char ch) {
        return find(guessedLetters.begin(), guessedLetters.end(), ch) != guessedLetters.end();
    }

    void processGuess(char ch) {
        guessedLetters.push_back(ch);
        bool correct = false;
        for (int i = 0; i < word.length(); ++i) {
            if (word[i] == ch) {
                displayWord[i] = ch;
                correct = true;
            }
        }
        if (!correct) {
            wrongAttempts++;
            cout << "Incorrect guess!\n";
        } else {
            cout << "Correct guess!\n";
        }
    }

    bool isGameWon() {
        return displayWord == word;
    }

    bool isGameOver() {
        return wrongAttempts >= maxAttempts;
    }

    void play() {
        cout << "**** HANGMAN GAME ****" << endl;
        while (!isGameWon() && !isGameOver()) {
            displayStatus();
            char guess;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = tolower(guess);
            if (!isalpha(guess)) {
                cout << "Invalid input! Please enter an alphabet.\n";
                continue;
            }
            if (isAlreadyGuessed(guess)) {
                cout << "You already guessed that letter!\n";
                continue;
            }
            processGuess(guess);
        }
        displayStatus();
        if (isGameWon()) {
            cout << "\nCongratulations! You guessed the word: " << word << endl;
        } else {
            cout << "\nGame Over! The word was: " << word << endl;
        }
    }
};

int main() {
    char choice;
    do {
        HangmanGame game;
        game.play();
        cout << "\nDo you want to play again? (y/n): ";
        cin >> choice;
    } while (tolower(choice) == 'y');
    return 0;
}
