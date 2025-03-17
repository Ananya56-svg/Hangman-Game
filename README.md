# Hangman Game Project in C++
### Developed by: Ananya Pandey

## 📌 Project Description:
This is a simple yet interactive implementation of the classic **Hangman Game**, developed using the **C++ programming language**. The game is designed to provide a console-based user experience where a player attempts to guess a hidden word letter-by-letter within a limited number of attempts.

The project demonstrates key C++ concepts like **file handling**, **loops**, **conditional statements**, **functions**, and **Object-Oriented Programming (OOP)** using **classes and objects**.

## 🎯 Key Features:
- Random word selection from an external file
- Limited guessing attempts (typically 6)
- ASCII-art based visual feedback on incorrect guesses
- Input validation and duplicate guess check
- Word progress display with correctly guessed letters
- Replay option after game ends
- Modular class-based structure using OOP

## ⚙ Technologies Used:
- **Language:** C++
- **Concepts:** OOP, File Handling, Loops, Functions, Conditionals
- **Tools/IDE:** Visual Studio Code / Dev-C++ / Code::Blocks
- **Compiler:** g++ (MinGW/GCC)

## 🗂 Project Structure:
```
HangmanGame/
├── hangman.cpp         # Main source code
├── words.txt           # File containing word list
└── README.md           # Project documentation
```

## 📂 Setup Instructions:
1. Clone or download this repository.
2. Create a file named `words.txt` in the same directory as the `hangman.cpp`.
3. Add some words into `words.txt`, each on a new line:
```
hello
world
india
apple
tiger
school
```
4. Compile the code:
```bash
g++ hangman.cpp -o hangman
```
5. Run the program:
```bash
./hangman
```

## 📷 Sample Output:
```
**** HANGMAN GAME ****

Word: _ _ _ _ _
Enter your guess: a
Incorrect guess!

   O

Word: _ _ _ _ _
Enter your guess: e
Correct guess!
...
```

## 🚀 Future Enhancements:
- Add difficulty levels and categorized word lists
- GUI version using Qt or SFML
- Multiplayer mode
- Scoreboard and leaderboard system
- Word contribution by users
- Web-based version

## 🙌 Acknowledgement:
This project has been designed and developed solely by **Ananya PANDEY** as a personal learning initiative to strengthen programming and problem-solving skills using C++.

## 📄 License:
This project is open for educational use. Feel free to use, modify, and share with credit.
